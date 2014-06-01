#ifndef CAVASCRIPT_ARRAY_H

#define CAVASCRIPT_ARRAY_H

#include "CavaObject.h"
#include "CavaString.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

namespace cavascript {

template<class T>
class Array : public Object {
public:
	Array();
	explicit Array(int i);
	Array(const char* list);
	~Array();

	// Member fields
	int length;

	// Member functions
	Array<T> concat(const Array<T>& another) const;
	int indexOf(const T& x) const;
	String join(const char& separator = ',') const;
	int lastIndexOf(const T& x) const;
	T pop();
	int push(T e);
	void reverse();
	T shift();
	Array<T> slice(int start, int end);
	Array<T> splice(int start, int len);
	void sort();
	String toString() const;
	int unshift(T x);
	Array<T>& valueOf() const;

	// Interfaces
	typename vector<T>::iterator _begin() const {
		return _arr.begin();
	}
	typename vector<T>::iterator _end() const {
		return _arr.end();
	}

	// Operators
	T& operator[](int i) {
		return _arr.at(i);
	}
	//void operator()(...) {

	//}

private:
	Array(vector<T> arr);
	vector<T> _arr;
};

template<class T>
Array<T>::Array() : length(0) {}

template<class T>
Array<T>::Array(int i) : _arr(i), length(i) {}

template<class T>
Array<T>::Array(const char* list) {

}

template<class T>
Array<T>::Array(const vector<T> arr) : _arr(arr), length(arr.size()) {}

template<class T>
Array<T>::~Array() {}

template<class T>
Array<T> Array<T>::concat(const Array<T>& another) const {
	vector<T> res = _arr;
	res.insert(res.end(), another._begin(), another._end());
	return Array<T>(res);
}

template<class T>
int Array<T>::indexOf(const T& x) const {
	vector<T>::const_iterator iter = find(_arr.begin(), _arr.end(), x);
	return iter == _arr.end() ? -1 : iter - _arr.begin();
}

template<class T>
String Array<T>::join(const char& separator = ',') const {
	ostringstream oss;
	for (vector<T>::const_iterator iter = _arr.begin(); iter != _arr.end(); ++iter) {
		oss << *iter;
		if (iter != _arr.end() - 1 && separator != '\0')
			oss << separator;
	}
	return String(oss.str());
}

template<class T>
int Array<T>::lastIndexOf(const T& x) const {
	vector<T>::const_reverse_iterator r_iter = _arr.rbegin();
	for (; r_iter != _arr.rend(); ++r_iter) {
		if (*r_iter == x)
			break;
	}
	return r_iter == _arr.rend() ? -1 : _arr.rend() - r_iter - 1;
}

template<class T>
int Array<T>::push(T e) {
	_arr.push_back(e);
	return ++length;
}

template<class T>
T Array<T>::pop() {
	T res = _arr.back;
	_arr.pop_back();
	--length;
	return res;
}

template<class T>
void Array<T>::reverse() {
	reverse(_arr.begin(), _arr.end());
}

template<class T>
T Array<T>::shift() {
	T res = _arr.front;
	_arr.erase(0);
	--length;
	return res;
}

template<class T>
Array<T> Array<T>::slice(int start, int end) {
	vector<T> res(_arr.begin() + start, _arr.begin() + end);
	return Array<T>(res);
}

template<class T>
Array<T> Array<T>::splice(int start, int len) {
	vector<T> res(_arr.begin() + start, _arr.begin() + start + len);
	_arr.erase(_arr.begin() + start, _arr.begin() + start + len);
	return Array<T>(res);
}

template<class T>
void Array<T>::sort() {
	sort(_arr.begin(), _arr.end());
}

template<class T>
String Array<T>::toString() const {
	return join();
}

template<class T>
int Array<T>::unshift(T x) {
	_arr.insert(_arr.begin(), x);
	return ++length;
}

template<class T>
Array<T>& Array<T>::valueOf() const {
	return *this;
}

}

#endif