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
/// POST: /login
RequestResult Request_POST_Login(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	// Parse and check credentials
	auto js = JSONParse(body);
	const std::string usr_id = js.get("id", "").asString();
	const std::string pwd = js.get("password", "").asString();
	Usuario usr;
	if(db->loadUsuario(usr_id, usr) && usr.password == pwd) {
		usr.last_action = std::time(nullptr);
		usr.token = genToken();
		db->saveUsuario(usr);
		ret.data = std::string("{ \"token\": \"") + usr.token + usr.nombre + "\" }";
		ret.code = 201;
	}else{
		ret.data = "{ \"error\": \"Usuario o clave invalidos\" }";
		ret.code = 401;
	}
	return ret;
}

/// GET: /test
RequestResult Request_GET_Test(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	//RequestResult ret;
	//ret.data = "{ \"Hello\": \"world\" }";
	//return ret;
	log.msg(LOG_TYPE::WARN, "Cerrando servidor via /test");
	exit(0);
}

/// POST: /usuario
RequestResult Request_POST_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	Usuario user;
	// Parseamos el JSON para cargar los datos posteados
	auto js = JSONParse(body);
	user.load(js);
	// Cargamos el usuario del uri
	user.id = uriparams;
	std::string err_str;
	if(db->createUsuario(user, err_str)) {
		ret.code = 201;
	}else{
		log.msg(LOG_TYPE::INFO, std::string("Error creando usuario `") + user.id + "`");
		ret.code = 401;
                ret.data = std::string("{ \"error\": \"") + err_str + "\" }";
	}
	return ret;
}

/// GET: /usuarios
RequestResult Request_GET_Usuarios(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
        RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
	}else{
		ret.data = db->getListaUsuariosJson(qdict["r_user"]);
	}
        return ret;
}

/// GET: /usuario
RequestResult Request_GET_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	Usuario usr;
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"]) || !db->loadUsuario(uriparams, usr)) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
	}else{
		ret.data = usr.asJson();
	}
	return ret;
}

/// PUT: /usuario
RequestResult Request_PUT_Usuario(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	Usuario usr;
	// Debe pasar la clave tambien
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
		return ret;
	}
	if(uriparams != qdict["r_user"]) {
		ret.code = 401;
		ret.data = "{\"error\": \"permiso denegado\" }";
		return ret;
	}
	if(!db->loadUsuario(uriparams, usr)) {
		ret.code = 500;
		ret.data = "{\"error\": \"error cargando usuario\" }";
		return ret;
	}
	if(qdict["password"] != usr.password) {
		ret.code = 401;
		ret.data = "{\"error\": \"password invalido\" }";
		return ret;
	}
	// Editamos los valores que nos pasaron (si los pasaron)
	auto js = JSONParse(body);
	usr.load(js);
	// Guardamos el usuario
	if(!db->saveUsuario(usr)) {
		// TODO: desdoblar en los distintos
		ret.code = 401;
		ret.data = "{ \"error\": \"atributos invalidos\" }";
	}else{
		ret.code = 201;
	}
	return ret;
}

/// POST: conversacion
RequestResult Request_POST_Conversacion(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
	}else{
		const auto& r_user = qdict["r_user"];
		const auto& t_user = uriparams;
		auto js = JSONParse(body);
                const auto& msg = js.get("mensaje", "").asString();
                if(msg.length() == 0) {
                	ret.code = 401;
                        ret.data = "{ \"error\": \"mensaje invalido\" }";
                }else if(!db->usuarioExists(t_user)){
			ret.code = 401;
                        ret.data = "{ \"error\": \"usuario de destino invalido\" }";
		}else if(!db->postearMensaje(r_user, t_user, msg)) {
			ret.code = 500;
                        ret.data = "{ \"error\": \"error al postear mensaje\" }";
		}else{
			// Todo ok
			ret.code = 201;
		}
	}
	return ret;
}


/// GET: /conversacion
RequestResult Request_GET_Conversacion(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
	}else{
		const auto& r_user = qdict["r_user"];
		const auto& t_user = uriparams;
		Conversacion conv;
		if(!db->loadConversacion(r_user, t_user, conv)) {
			ret.code = 500;
                        ret.data = "{ \"error\": \"error al cargar conversacion\" }";
		}else{
			int lines;
			try {
				lines = std::stoi(qdict["lines"]);
			}catch(...) {
				lines = 0;
			}
			ret.data = conv.asJson(lines);
			db->markRead(r_user, t_user);
		}
	}
	return ret;
}


/// GET: /broadcast
RequestResult Request_GET_Broadcast(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
        auto qdict = parseQueryParams(qparams);
        if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
        	ret.code = 401;
                ret.data = "{\"error\": \"token invalido\" }";
        }else{
                Broadcast bcast;
                if(!db->loadBroadcast(bcast)) {
                	ret.code = 500;
                        ret.data = "{ \"error\": \"error al cargar broadcast\" }";
                }else{
                        int lines;
                        try {
                                lines = std::stoi(qdict["lines"]);
                        }catch(...) {
                                lines = 0;
                        }
                        ret.data = bcast.asJson(lines);
			// Marco como leido
                        db->markBroadcastUnread(qdict["r_user"], false);
                }
        }
        return ret;
}

/// POST: /broadcast
RequestResult Request_POST_Broadcast(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
	RequestResult ret;
	auto qdict = parseQueryParams(qparams);
	if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
		ret.code = 401;
		ret.data = "{\"error\": \"token invalido\" }";
	}else{
		const auto& r_user = qdict["r_user"];
		auto js = JSONParse(body);
                const auto& msg = js.get("mensaje", "").asString(); 
                if(msg.length() == 0) {
                        ret.code = 401;
                        ret.data = "{ \"error\": \"Mensaje invalido\" }";
		}else if(!db->postearMensajeBroadcast(r_user, msg)) {
			ret.code = 500;
                        ret.data = "{ \"error\": \"error al postear broadcast\" }";
		}else{
			// Todo ok
			ret.code = 201;
		}
	}
	return ret;
}


// Install them
void RequestHandler::installRequests(Database* db) {

	// Store db pointer
	this->db = db;
	// Format: install("method.URI", Request)
	install("GET./test", Request_GET_Test);
	install("POST./login", Request_POST_Login);
	install("GET./usuarios", Request_GET_Usuarios);
	install("POST./usuario", Request_POST_Usuario);
	install("GET./usuario", Request_GET_Usuario);
	install("PUT./usuario", Request_PUT_Usuario);
	install("GET./conversacion", Request_GET_Conversacion);
	install("POST./conversacion", Request_POST_Conversacion);
	install("POST./broadcast", Request_POST_Broadcast);
	install("GET./broadcast", Request_GET_Broadcast);
}
