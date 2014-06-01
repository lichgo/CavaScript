#ifndef CAVASCRIPT_STRING_H

#define CAVASCRIPT_STRING_H

#include "CavaObject.h"
#include <string>
#include <ostream>

namespace cavascript {

class String : public Object {
	
public:
	String();
	String(const char* str);
	String(const std::string& str);

	// Member fields
	int length;

	// Member functions
	char charAt(int i) const;
	int charCodeAt(int i) const;
	String concat(String& another) const;
	int indexOf(String& substr) const;
	int lastIndexOf(String& susstr) const;
	int localeCompare(String& another) const;

	
	// Static
	static char fromCharCode(int i);

	// Interfaces
	std::string _getStr() const {
		return _str;
	}

	// Operators
	bool operator==(const String& another) {
		return _getStr() == another._getStr();
	}
	
private:
	std::string _str;
};

String::String() : length(0) {}

String::String(const char* str) : _str(str) {
	length = _str.size();
}

String::String(const std::string& str) : _str(str) {
	length = _str.size();
}

// Operator
std::ostream& operator<<(std::ostream& out, String& str) {
	out << str._getStr();
	return out;
}

}

#endif