#ifndef CAVASCRIPT_OBJECT_H

#define CAVASCRIPT_OBJECT_H

#include "String.h"

namespace cavascript {

class Object {
public:
	Object();
	virtual ~Object();
	virtual String toString();
};

}

#endif