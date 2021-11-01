#ifndef CN_HUST_LYH_BASIC_STRING_H
#define CN_HUST_LYH_BASIC_STRING_H

/// <summary>
/// 这个头文件实现basic_string，
/// 接口名称以及返回类型参考：https ://en.cppreference.com/w/cpp/string/basic_string
/// 
/// </summary>

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

	basic_string() {};
};
}

#endif	//CN_HUST_LYH_BASIC_STRING_H