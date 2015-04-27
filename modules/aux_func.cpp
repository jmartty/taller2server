#include "aux_func.h"

std::vector<std::string> explode(const std::string& delim, const std::string& str) {

	if(delim.size() == 0 || str.size() == 0)
		return std::vector<std::string>();
	// the array, intiailized with the string we're looking in
	// in case we don't find delim in it
	std::vector<std::string> retarr(1, str);
	std::string::size_type loc = str.find(delim, 0);
	if(loc == std::string::npos){
		return retarr;
	}else{
		//found delim in str, clear the array
		std::vector<std::string>::iterator first = retarr.begin();
		retarr.erase(first);
		//add the different exploded strings
		std::string::size_type nextloc = 0;
		loc = 0;
		while(nextloc != std::string::npos){
			nextloc = str.find(delim, loc);
			retarr.push_back(str.substr(loc, nextloc-loc));
			loc = str.find(delim,loc) + delim.size();
		}
		return retarr;
	}

}
