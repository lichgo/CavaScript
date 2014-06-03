#ifndef CAVASCRIPT_OBJECT_H

#define CAVASCRIPT_OBJECT_H

#include <string>
#include <unordered_map>

using namespace std;

namespace cavascript {

class Object {
public:
	Object() {}
	virtual ~Object() {}
	virtual std::string toString() {
		return std::string("Object");
		_map[1] = 2;
	}
	//virtual Object& valueOf() const {
	//	return *this;
	//}

	virtual int& hash() {
		return _map[2];
	}

	// Operators
	virtual int& operator[](const string& key) const {
		return _map[2];
	}

private:
	unordered_map<int, int> _map;
};

}

#endif