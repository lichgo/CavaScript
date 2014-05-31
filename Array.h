#ifndef CAVASCRIPT_ARRAY_H

#define CAVASCRIPT_ARRAY_H

#include "Object.h"
#include "String.h"
#include <cstdarg>
#include <vector>
#include <string>
#include <algorithm>

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
	T& pop();
	int push(T e);
	void reverse();
	T& shift();
	Array<T> slice(int start, int end);
	//Array<T> splice(int start, int length, ...);
	void sort();
	String toString() const;
	int unshift();
	Array<T>& valueOf() const;

	// Interfaces
	typename vector<T>::iterator _begin() const {
		return _arr.begin();
	}
	typename vector<T>::iterator _end() const {
		return _arr.end();
	}

	// Operators
	T& operator[](int i) const {
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
	string str;
	for (vector<T>::const_iterator iter = _arr.begin(); iter != _arr.end(); ++iter) {
		str.append(*iter);
		if (iter != _arr.end() - 1)
			str.append(separator);
	}
	return new String(str);
}

template<class T>
int Array<T>::lastIndexOf(const T& x) const {
	vector<T>::reverse_iterator r_iter;
	for (r_iter = _arr.rbegin(); r_iter != _arr.rend(); ++r_iter) {
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

}

#endif