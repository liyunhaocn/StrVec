#include "Vector.h"


namespace util {

	Vector::Vector() {
		_data = new int[1];
	}

	Vector::Vector(size_t _len) :_len(_len) {
		_data = new int[_len];
	}

	Vector::Vector(size_t _len, int val) : _len(_len) {
		_data = new int[_len];
		for (size_t i = 0; i < _len; ++i) {
			_data[i] = val;
		}
	}

	void Vector::push_back(const int& val) {
		if (_len >= _cap) {
			reAlloc(_len * 2);
		}
		this->_data[_len] = val;
		++_len;
	}

	size_t Vector::capacity() {
		return _cap;
	}

	void Vector::show() {
		std::cout << "[";
		for (int i = 0;i<_len;++i) {
			std::cout << _data[i] << ",";
		}
		std::cout << "]" << std::endl;
	}

	int& Vector::operator [](size_t index) {
		return _data[index];
	}

	bool Vector::reAlloc(const int len) {

		int* longer = new int[len];
		for (size_t i = 0; i < _len; ++i) {
			longer[i] = _data[i];
		}
		delete[] _data;
		_data = longer;
		_cap = len;
		return true;
	}

	Vector::~Vector() {
		if (_data) {
			_len = 0;
			delete[]  _data;
		}
	}
}
