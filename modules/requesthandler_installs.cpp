#include "requesthandler.h"
#include "database.h"

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
		if(db->createUsuario(user)) {
		}else{
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
		auto lu = db->getListaUsuarios();
		auto c = lu.size();
		// Build JSON reply
		ret.data = "{ \"usuarios\": [ ";
		size_t i = 0;
		for(const auto& u : lu) {
			ret.data += "\"";
			ret.data += u;
			ret.data += "\"";
			if(i != c)
				ret.data += ", ";
			i++;
		}
		ret.data += " ] }";
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

}
