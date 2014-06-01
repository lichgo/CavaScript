#ifndef CAVASCRIPT_OBJECT_H

#define CAVASCRIPT_OBJECT_H

#include <string>

namespace cavascript {

class Object {
public:
	Object() {}
	virtual ~Object() {}
	virtual std::string toString() {
		return std::string("Object");
	}
};

}

#endif