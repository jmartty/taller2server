#include <json/json.h>
#include <string>
#include <iostream>

int main() {

	Json::Value root;
	Json::Reader reader;

	std::string source = "{\"foo\": \"bar\"}";
	reader.parse(source, root);

	std::string foo_val = root["foo"].asString();
	std::cout << "foo: " << foo_val << std::endl;
}
