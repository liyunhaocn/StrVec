
#ifndef CN_HUST_LYH_BASIC_STRING_H
#define CN_HUST_LYH_BASIC_STRING_H

/// <summary>
/// 这个头文件实现basic_string，
/// 接口名称以及返回类型参考：https ://en.cppreference.com/w/cpp/string/basic_string
/// 
/// </summary>

#include <string.h>

namespace tstd{

template<typename CharT>
class basic_string {
public:
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

	basic_string() {};

	basic_string(const char * cs) {

		size_t len = strlen(cs);
		_begin = new char[len + 1];
		strcpy(_begin,cs);
		_end = _begin + len + 1;
		_cap = _end;
	};

	iterator begin() {
		return _begin;
	}

	iterator end() {
		return _end;
	}

	size_type capacity() {
		return _cap - _begin();
	}

	size_type length() {
		return _end - _begin;
	}
	
	size_type size() const {
		return _end - _begin;
	}

	friend std::ostream& operator << (std::ostream& osm, const basic_string& s){

		for (size_type i = 0; i < s.size(); ++i) {
			osm << s[i];
		}
			
		return osm;
	}

	// 访问元素相关操作
	reference       operator[](size_type n)
	{
		assert(n <= size());
		if (n == size())
			*(_begin + n) = value_type();
		return *(_begin + n);
	}
	const_reference operator[](size_type n) const
	{
		//assert(n <= size());
		if (n == size()) {
			*(_begin + n) = value_type();
		}
			
		return *(_begin + n);
	}

private:
	iterator _begin;
	iterator _end;
	iterator _cap;

};
}

#endif	//CN_HUST_LYH_BASIC_STRING_H