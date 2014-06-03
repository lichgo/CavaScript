#ifndef CAVASCRIPT_STRING_H

#define CAVASCRIPT_STRING_H

#include "CavaObject.h"
#include <string>
#include <iostream>
#include <cctype>

namespace cavascript {

template<class T>
class Array;

class String : public Object {
	friend std::ostream& operator<<(std::ostream& out, String& str);

public:
	String();
	String(const char* str);
	String(const std::string& str);

	// Member fields
	unsigned int length;

	// Member functions
	char charAt(int i) const;
	unsigned short charCodeAt(int i) const;
	String concat(String& another) const;
	int indexOf(String& substr) const;
	int lastIndexOf(String& susstr) const;
	int localeCompare(String& another) const;
	/*
	match, replace, search
	*/
	String slice(int start, int end) const;
	String substr(int start, int len) const;
	String substring(int start, int end) const;
	Array<String> split(const char& separator) const;
	String toLowerCase() const;
	String toUpperCase() const;
	String toLocaleLowerCase() const;
	String toLocaleUpperCase() const;
	
	// Static
	static char fromCharCode(int i);

	// Operators
	bool operator==(const String& another) {
		return _str == another._str;
	}
	
private:
	std::string _str;
};

String::String() : length(0) {}

String::String(const char* str) : _str(str) {
	length = _str.size();
}

String::String(const std::string& str) : _str(str) {}

char String::charAt(int i) const {
	return _str.at(i);
}

unsigned short String::charCodeAt(int i) const {
	return (unsigned short)(_str.at(i));
}

String String::substr(int start, int len) const {
	return String(_str.substr(start, len));
}

String String::substring(int start, int end) const {
	return String(_str.substr(start, end - start));
}

String String::slice(int start, int end) const {
	return substring((start + _str.size()) % _str.size(), (end + _str.size()) % _str.size());
}

//Array<String> String::split(const char& separator) const {
//	Array<String> arr;
//	size_t start = 0;
//	size_t found = _str.find_first_of(separator, start);
//	while (found != string::npos) {
//		arr.push(substring(start, found));
//		start = found + 1;
//		found = _str.find_first_of(separator, start);
//	}
//	return arr;
//}

String String::toUpperCase() const {
	string res = _str;
	for (string::iterator p = res.begin(); p != res.end(); ++p)
		*p = toupper(*p);
	return String(res);
}

String String::toLowerCase() const {
	string res = _str;
	for (string::iterator p = res.begin(); p != res.end(); ++p)
		*p = tolower(*p);
	return String(res);
}

// Operator
std::ostream& operator<<(std::ostream& out, String& str) {
	out << str._str;
	return out;
}

}

#endif