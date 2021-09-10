#include "Vector.h"
#include "funGlobal.h"

namespace util {

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
	
	size_t Vector::size() const {
		return _len;
	}

	void Vector::show() {
		std::cout << "[";
		for (int i = 0;i<_len;++i) {
			std::cout << _data[i] << ",";
		}
		std::cout << "]" << std::endl;
	}

	int& Vector::operator [](size_t index) const {
		return _data[index];
	}

	Vector::Vector() :_len(0) ,_cap(0),_data(nullptr){
		
		println("call: Vector()");
		_data = new int[1];
	}

	Vector::Vector(size_t _len):_len(_len),_cap(_len) {
		println("call:Vector(size_t _len)");
		_data = new int[_len];

	}

	Vector::Vector(size_t _len, int val) : Vector(_len) {

		println("call:Vector(size_t _len, int val)");
		for (size_t i = 0; i < _len; ++i) {
			_data[i] = val;
		}
	}
	
	Vector::Vector(const Vector& lval) :_len(lval._len),_cap(lval._cap) {

		println("call:Vector(const Vector& lval)");

		_data = new int[_len];
		for (size_t i = 0; i < lval.size(); ++i) {
			(*this)[i] = lval[i];
		}
	}
	
	Vector::Vector(Vector&& rval) noexcept :_len(rval._len),_cap(rval._cap),_data(rval._data) {

		println("call:Vector(Vector&& rval) noexcept");
		rval._data = nullptr;
		rval._cap = 0;
		rval._len = 0;
	}

	Vector& Vector::operator = (const Vector& lval) {
		
		println("call:operator =(const Vector& lval)");

		if (this != &lval) {
			delete[] _data;
			_data = new int[_len];
			_len = lval._len;
			_cap = lval._cap;

			for (size_t i = 0; i < lval.size(); ++i) {
				(*this)[i] = lval[i];
			}
		}
		
		return *this;
	}
	
	Vector& Vector::operator = (Vector&& rval) noexcept {
		
		println("call:operator =(Vector&& rval) noexcept");

		if (this != &rval) {
			delete[] _data;
			_data = rval._data;
			_len = rval._len;
			_cap = rval._cap;

			rval._data = nullptr;
			rval._cap = 0;
			rval._len = 0;
		}
		return *this;
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

		println("call:~Vector()");
		println(_data);
		println(_data==nullptr);
		if (_data) {
			_len = 0;
			_cap = 0;
			delete[]  _data;
			_data = nullptr;
		}
	}
}
