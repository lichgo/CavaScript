#include "CavaArray.h"
#include "CavaString.h"
#include <iostream>

using namespace cavascript;
using namespace std;

int main() {
	Array<int> arr;
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.unshift(4);
	cout << arr.length << endl;
	cout << arr.join() << endl;
	cout << ( arr.join() == String("4,1,2,3") );
}