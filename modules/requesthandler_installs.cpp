#include "aux_func.h"
#include "requesthandler.h"
#include "database.h"
#include "logger.h"
#include <string>
#include <json/json.h>

static Logger& log = Logger::get();
// JSON parser helper
Json::Value JSONParse(const std::string& source) {
	Json::Value root;
	Json::Reader reader;
	reader.parse(source, root);
	return root;
}


// Define all requests here
struct Request_POST_Login : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		// Parse and check credentials
		auto js = JSONParse(body);
		const std::string usr_id = js.get("id", "").asString();
		const std::string pwd = js.get("password", "").asString();
		Usuario usr;
		if(db->loadUsuario(usr_id, usr) && usr.password == pwd) {
			usr.last_action = std::time(nullptr);
			usr.token = Request::genToken();
			db->saveUsuario(usr);
			ret.data = std::string("{ \"token\": \"") + usr.token + "\" }";
			ret.code = 201;
		}else{
			ret.data = "{ \"error\": \"Usuario o clave invalidos\" }";
			ret.code = 401;
		}
		return ret;
	}
};

struct Request_GET_Test : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		ret.data = "{ \"Hello\": \"world\" }";
		return ret;
	}
};

struct Request_POST_Usuario : public Request {
        virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
                RequestResult ret;
		Usuario user;
		// Parseamos el JSON para cargar los datos posteados
		auto js = JSONParse(body);
		user.load(js);
		// Cargamos el usuario del uri
		user.id = uriparams;
		if(db->createUsuario(user)) {
			ret.code = 201;
		}else{
			log.msg(LOG_TYPE::INFO, std::string("Error creando usuario `") + user.id + "`");
			// TODO: desdoblar en casos distintos para cada tipo de error
			ret.code = 400;
	                ret.data = "{ \"error\": \"Atributos invalidos o usuario ya existe\" }";
		}
                return ret;
        }
};

struct Request_GET_Usuarios : public Request {
        virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
                RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.code = 401;
		}else{
			ret.data = db->getListaUsuariosJson(qdict["r_user"]);
		}
                return ret;
        }
};

struct Request_GET_Usuario : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		Usuario usr;
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"]) || !db->loadUsuario(uriparams, usr)) {
			ret.code = 401;
		}else{
			ret.data = usr.asJson();
		}
		return ret;
	}
};

struct Request_PUT_Usuario : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		Usuario usr;
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"]) || uriparams != qdict["r_user"] || !db->loadUsuario(uriparams, usr)) {
			ret.code = 401;
		}else{
			// Editamos los valores que nos pasaron (si los pasaron)
			// Guardamos el usuario
			auto js = JSONParse(body);
			const std::string nombre = js.get("nombre", "!").asString();
			if(nombre != "!") usr.nombre = nombre;
			const std::string password = js.get("password", "!").asString();
			if(password != "!") usr.password = password;
			const std::string foto = js.get("foto", "!").asString();
			if(foto != "!") usr.foto = foto;
			const std::string ubicacion = js.get("ubicacion", "!").asString();
			if(ubicacion != "!") usr.ubicacion = ubicacion;
			if(!db->saveUsuario(usr)) {
				ret.code = 400;
				ret.data = "{ \"error\": \"Atributos invalidos\" }";
			}
			else {
				ret.code = 201;
			}
		}

		return ret;
	}
};

struct Request_POST_Conversacion : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.code = 401;
		}else{
			const auto& r_user = qdict["r_user"];
			const auto& t_user = uriparams;
			auto js = JSONParse(body);
                        const auto& msg = js.get("mensaje", "").asString(); 
                        if(msg.length() == 0) {
                                ret.code = 400;
                                ret.data = "{ \"error\": \"Mensaje invalido\" }";
                        }else if(!db->usuarioExists(t_user)){
				ret.code = 400;
			}else if(!db->postearMensaje(r_user, t_user, msg)) {
				ret.code = 500;
			}else{
				// Todo ok
				ret.code = 201;
			}
		}
		return ret;
	}
};

struct Request_GET_Conversacion : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.code = 401;
		}else{
			const auto& r_user = qdict["r_user"];
			const auto& t_user = uriparams;
			Conversacion conv;
			if(!db->loadConversacion(r_user, t_user, conv)) {
				ret.code = 500;
			}else{
				ret.data = conv.asJson();
				db->markRead(r_user, t_user);
			}
		}
		return ret;
	}
};


struct Request_POST_Broadcast : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		auto qdict = Request::parseQueryParams(qparams);
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.code = 401;
		}else{
			const auto& r_user = qdict["r_user"];
			auto js = JSONParse(body);
                        const auto& msg = js.get("mensaje", "").asString(); 
                        if(msg.length() == 0) {
                                ret.code = 400;
                                ret.data = "{ \"error\": \"Mensaje invalido\" }";
			}else if(!db->postearMensajeTodos(r_user, msg)) {
				ret.code = 500;
			}else{
				// Todo ok
				ret.code = 201;
			}
		}
		return ret;
	}
};


// Install them
void RequestHandler::installRequests(Database* db) {

	// Store db pointer
	this->db = db;
	// Format: install("method.URI", Request)
	install("GET./test", new Request_GET_Test);
	install("POST./login", new Request_POST_Login);
	install("GET./usuarios", new Request_GET_Usuarios);
	install("POST./usuario", new Request_POST_Usuario);
	install("GET./usuario", new Request_GET_Usuario);
	install("PUT./usuario", new Request_PUT_Usuario);
	install("GET./conversacion", new Request_GET_Conversacion);
	install("POST./conversacion", new Request_POST_Conversacion);
	install("POST./broadcast", new Request_POST_Broadcast);
}
