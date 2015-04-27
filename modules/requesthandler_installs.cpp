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
		if(qdict.size() < 2 || !db->validateSession(qdict["r_user"], qdict["token"])) {
			ret.code = 401;
		}else{
			ret.data = db->getListaUsuariosJson();
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
