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
struct Request_PUT_Login : public Request {
	virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
		RequestResult ret;
		// Do something
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
		}else{
			log.msg(LOG_TYPE::INFO, std::string("Error creando usuario `") + user.id + "`");
			// TODO: desdoblar en dos casos
			ret.code = 400;
	                ret.data = "{ \"error\": \"Usuario invalido o ya existente\" }";
		}
                return ret;
        }
};

struct Request_GET_Usuarios : public Request {
        virtual RequestResult process(Database* db, const std::string& uriparams, const std::string& qparams, const std::string& body) {
                RequestResult ret;
		ret.data = db->getListaUsuariosJson();
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
	install("PUT./Login", new Request_PUT_Login);
	install("GET./Test", new Request_GET_Test);
	install("GET./Usuarios", new Request_GET_Usuarios);
	install("POST./Usuario", new Request_POST_Usuario);
	install("GET./Usuario", new Request_GET_Usuario);
}
