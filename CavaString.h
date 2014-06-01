#ifndef CAVASCRIPT_STRING_H

#define CAVASCRIPT_STRING_H

#include "CavaObject.h"
#include <string>

namespace cavascript {

class String : public Object {
public:
	String();
	String(const char* str);
	String(const std::string& str);
private:
	std::string _str;
};

String::String() {}

String::String(const char* str) : _str(str) {}

String::String(const std::string& str) : _str(str) {}

}

#endif