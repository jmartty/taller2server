#include <functional>
#include <algorithm>
#include <string>
#include "aux_func.h"
#include "request.h"

std::string Request::genToken() {

        auto randchar = []() -> char
        {
                static const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
                const size_t max_index = (sizeof(charset) - 1);
                return charset[ rand() % max_index ];
        };
        const size_t length = 8;
        std::string str(length, 0);
        std::generate_n(str.begin(), length, randchar);
        return str;

}

QParams Request::parseQueryParams(const std::string& qparams) {

	// Separamos por "&" y despues por "="
	// Ejemplo: qparams: "foo=bar&baz=qux"
	// param_dict["foo"] = "bar"
	// param_dict["baz"] = "qux"
	QParams param_dict;
	auto tokens = explode("&", qparams);
	for(auto& token : tokens) {
		const auto tmp = explode("=", token);
		// Safety check
		if(tmp.size() == 2) param_dict[tmp[0]] = tmp[1];
	}
	return param_dict;

}
