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
		const std::string usr_id = js.get("user", "").asString();
		const std::string pwd = js.get("pwd", "").asString();
		Usuario usr;
		if(db->loadUsuario(usr_id, usr) && usr.password == pwd) {
			usr.last_action = std::time(nullptr);
			usr.token = Request::genToken();
			db->saveUsuario(usr);
			ret.data = std::string("{ \"token\": \"") + usr.token + "\" }";
			ret.code = 201;
		}else{
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
		// Cargamos el usuario del uri
		user.id = uriparams;
		// Parseamos el JSON para cargar los datos posteados
		auto js = JSONParse(body);
		user.load(js);
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
		if(qdict.size() < 2) {
			ret.code = 401;
			return ret;
		}
		Usuario usr;
		db->loadUsuario(qdict["r_user"], usr);
		if(db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.data = db->getListaUsuariosJson();
		}else{
			ret.code = 401;
		}
                return ret;
        }
};

struct Request_GET_Usuario : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		Usuario usr;
		if(!db->loadUsuario(uriparams, usr)) {
			ret.code = 404;
		}else{
			ret.code = 200;
			ret.data = usr.asJson();
		}
		return ret;
	}
};

// Install them
void RequestHandler::installRequests(Database* db) {

	// Store db pointer
	this->db = db;
	// Format: install("method.URI", Request)
	install("POST./login", new Request_POST_Login);
	install("GET./test", new Request_GET_Test);
	install("GET./usuarios", new Request_GET_Usuarios);
	install("POST./usuario", new Request_POST_Usuario);
	install("GET./usuario", new Request_GET_Usuario);
}
