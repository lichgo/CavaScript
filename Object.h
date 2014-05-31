#ifndef CAVASCRIPT_OBJECT_H

#define CAVASCRIPT_OBJECT_H

namespace cavascript {

class String;

class Object {
public:
	Object() {}
	virtual ~Object() {}
	//virtual Object toString() {
	//	return String("Object");
	//}
};

}

#endif