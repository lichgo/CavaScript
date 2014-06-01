#include "Array.h"
#include <iostream>

using namespace cavascript;
using namespace std;

int main() {
	Array<int> arr;
	arr.unshift(0, 1, 2, 3);
	cout << arr.length << endl;
}