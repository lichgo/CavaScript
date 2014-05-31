#ifndef CAVASCRIPT_STRING_H

#define CAVASCRIPT_STRING_H

#include "Object.h"
#include <string>

using namespace std;

namespace cavascript {

class String : public Object {
public:
	String();
	String(const char* str);
	String(const string& str);
private:
	string _str;
};

String::String() {}

String::String(const char* str) : _str(str) {}

String::String(const string& str) : _str(str) {}

}

#endif