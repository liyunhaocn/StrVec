
#ifndef CN_HUST_LYH_BASIC_STRING_H
#define CN_HUST_LYH_BASIC_STRING_H

/// <summary>
/// 这个头文件实现basic_string，
/// 接口名称以及返回类型参考：https ://en.cppreference.com/w/cpp/string/basic_string
/// 
/// </summary>

#include <string.h>
#include <xutility>

namespace tstd{

template<typename CharT, class CharTraits = std::char_traits<CharT>>
class basic_string {

public:

	using traits_type = CharTraits;
	using char_traits = CharTraits;

	using allocator_type	= allocator<CharT>;
	using data_allocator	= allocator<CharT>;

	using value_type		= typename allocator_type::value_type;
	using pointer			= typename allocator_type::pointer;
	using const_pointer		= typename allocator_type::const_pointer;
	using reference			= typename allocator_type::reference;
	using const_reference	= typename allocator_type::const_reference;
	using size_type			= typename allocator_type::size_type;
	using difference_type	= typename allocator_type::difference_type;

	using iterator = value_type*;
	using const_iterator = const value_type* ;
	using reverse_iterator = std::reverse_iterator<iterator>        ;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	basic_string():_begin(nullptr),_end(nullptr),_cap(nullptr) {};

	basic_string(const char * cs) {

		size_t len = strlen(cs);
		_begin = new char[len + 1];
		strcpy(_begin,cs);
		_end = _begin + len + 1;
		_cap = _end;
	};
	
	basic_string(size_type n, value_type ch) {

		_begin = new char[n + 1];
		for (int i = 0; i < n; ++i) {
			_begin[i] = ch;
		}
		_begin[n] = '\0';
		_end = _begin + n + 1;
		_cap = _end;
	}

	basic_string(const basic_string& rhs, size_type pos) {
		assert(pos <= rhs.size());

		int n = rhs.size() - pos;
		_begin = new char[n + 1];
		for (int i = 0; i < n; ++i) {
			_begin[i] = rhs[i];
		}
		_begin[n] = '\0';
		_end = _begin + n + 1;
		_cap = _end;

	}

	basic_string(const basic_string& rhs, size_type pos, size_type n){

		_begin = new char[n + 1];
		for (int i = 0; i < n; ++i) {
			_begin[i] = rhs[pos+i];
		}
		_begin[n] = '\0';
		_end = _begin + n + 1;
		_cap = _end;
	}

	//basic_string(const_pointer str) {
	//	const char* p = str;
	//	basic_string(p);
	//}

	basic_string(const_pointer str, size_type count) {
		basic_string(str, 0, count);
	}

	template <class Iter, typename std::enable_if<
		std::_Is_iterator<Iter>::value, int>::type = 0>
		basic_string(Iter first, Iter last) {

		int n = last - first;

		_begin = new char[n + 1];
		for (int i = 0; i < n; ++i) {
			_begin[i] = first[i];
		}
		_begin[n] = '\0';
		_end = _begin + n + 1;
		_cap = _end;
	}

	basic_string(const basic_string& rhs) {
		
		int n = rhs.size();
		_begin = new char[n + 1];

		for (int i = 0; i < n; ++i) {
			_begin[i] = rhs[i];
		}
		_begin[n] = '\0';
		_end = _begin + n;
		_cap = _end;
	}

	basic_string(basic_string&& rhs) noexcept
		:_begin(rhs._begin), _end(rhs._end), _cap(rhs._cap) {
		rhs._begin = nullptr;
		rhs._end = 0;
		rhs._cap = 0;
	}

	basic_string& operator=(const basic_string& rhs) {
		*this = basic_string(rhs);
		return *this;
	}

	basic_string& operator=(basic_string&& rhs) noexcept {
		
		this->_begin = rhs._begin;
		this->_end = rhs._end;
		this->_cap = rhs._cap;

		rhs._begin = nullptr;
		rhs._end = 0;
		rhs._cap = 0;

		return *this;
	}

	basic_string& operator=(const_pointer str) {
		*this = basic_string(str);
		return *this;
	}

	basic_string& operator=(value_type ch) {

		basic_string(1,ch);
		return *this;
	}

	~basic_string() { 
		delete _begin;
		_begin = nullptr;
		_end = nullptr;
		_cap = nullptr;
	}

	size_type max_size() const noexcept {
		return static_cast<size_type>(-1);
	}

	bool empty() const noexcept{
		return size() == 0;
	}

	size_type size() const {
		return _end - _begin;
	}
	
	size_type length() {
		return _end - _begin;
	}
	
	size_type capacity() {
		return _cap - _begin;
	}

	iterator begin() noexcept{
		return _begin;
	}
	const_iterator begin() const noexcept {
		return _begin;
	}

	iterator end() noexcept {
		return _end;
	}

	const_iterator end() const noexcept {
		return _end;
	}

	reverse_iterator rbegin() noexcept {
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin()  const noexcept {
		return const_reverse_iterator(end());
	}

	reverse_iterator rend() noexcept {
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const noexcept {
		return const_reverse_iterator(begin());
	}

	const_iterator cbegin()  const noexcept {
		return begin();
	}

	const_iterator cend() const noexcept {
		return end();
	}

	const_reverse_iterator crbegin() const noexcept {
		return rbegin();
	}

	const_reverse_iterator crend() const noexcept {
		return rend();
	}

	friend std::ostream& operator << (std::ostream& osm, const basic_string& s) {

		for (size_type i = 0; i < s.size(); ++i) {
			osm << s[i];
		}
			
		return osm;
	}

	reference operator[](size_type n) {
		assert(n <= size());
		if (n == size())
			*(_begin + n) = value_type();
		return *(_begin + n);
	}

	const_reference operator[](size_type n) const {
		//assert(n <= size());
		if (n == size()) {
			*(_begin + n) = value_type();
		}
		return *(_begin + n);
	}

	reference front() {
		assert(!empty());
		return *begin();
	}
	const_reference front() const
	{
		assert(!empty());
		return *begin();
	}

	reference back() {
		assert(!empty());
		return *(end() - 1);
	}
	const_reference back()  const {
		assert(!empty());
		return *(end() - 1);
	}

	const_pointer   data()  const noexcept{
		return _begin;
	}

	const_pointer   c_str() const noexcept {
		return begin();
	}

private:
	iterator _begin;
	iterator _end;
	iterator _cap;

};
}

#endif	//CN_HUST_LYH_BASIC_STRING_H