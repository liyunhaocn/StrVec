#include "Vector.h"
#include "funGlobal.h"

namespace util {

	void Vector::push_back(const value_type& val) {
		*_end = val;
		
	}

	Vector::size_type Vector::capacity() {
		return static_cast<size_type>(_cap - _begin);
	}
	
	Vector::size_type Vector::size() const {
		return static_cast<size_type>(_end - _begin);
	}

	void Vector::show() {
		std::cout << "[";
		for (iterator it = _begin;it!= _end; ++it) {
			std::cout << *it << ",";
		}
		std::cout << "]" << std::endl;
	}

	int& Vector::operator [](size_t index) const {
		return * (_begin+index);
	}

	Vector::Vector() :_begin(nullptr) ,_end(nullptr),_cap(nullptr){
		println("call: Vector()");
	}

	Vector::Vector(size_type n){
		println("call:Vector(size_t _len)");
		_begin = allocate(n);
		_end = _begin + n;
		_cap = _begin + n;
		std::fill(_begin,_end,0);
	}

	Vector::Vector(size_type n, value_type val){

		println("call:Vector(size_t _len, int val)");
		_begin = allocate(n);
		_end = _begin + n;
		_cap = _begin + n;
		std::fill(_begin, _end, val);
	}
	
	Vector::Vector(const Vector& lval){

		println("call:Vector(const Vector& lval)");
		size_type n = lval.size();
		_begin = allocate(n);
		_end = _begin + n;
		_cap = _begin + n;

		for (size_t i = 0; i < lval.size(); ++i) {
			(*this)[i] = lval[i];
		}
	}
	
	Vector::Vector(Vector&& rval) noexcept :_begin(rval._begin), _end(rval._end),_cap(rval._cap) {

		println("call:Vector(Vector&& rval) noexcept");
		rval._begin = nullptr;
		rval._end = nullptr;
		rval._cap = nullptr;
	}

	Vector& Vector::operator = (const Vector& lval) {
		
		println("call:operator =(const Vector& lval)");

		if (this != &lval) {
			delete[] _begin;
			size_type n = lval.size();
			_begin = allocate(n);
			_end = _begin + n;
			_cap = _begin + n;

			for (size_t i = 0; i < lval.size(); ++i) {
				(*this)[i] = lval[i];
			}
		}
		
		return *this;
	}
	
	Vector& Vector::operator = (Vector&& rval) noexcept {
		
		println("call:operator =(Vector&& rval) noexcept");

		if (this != &rval) {
			delete[] _begin;
			_begin = rval._begin;
			_end = rval._end;
			_cap = rval._cap;

			rval._begin = nullptr;
			rval._end = nullptr;
			rval._cap = nullptr;
		}
		return *this;
	}

	Vector::pointer Vector::allocate(size_type n) {
		if (n == 0)
			return nullptr;
		return static_cast<pointer>(::operator new(n * sizeof(value_type)));
	}

	Vector::~Vector() {

		println("call:~Vector()");
		println(_begin);
		println(_begin ==nullptr);
		if (_begin) {

			delete[]  _begin;

			_begin = nullptr;
			_end = nullptr;
			_cap = nullptr;
		}
	}
}
