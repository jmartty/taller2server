#include <functional>
#include <algorithm>
#include <string>

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

