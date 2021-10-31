#ifndef CN_HUST_LYH_BASIC_STRING_H
#define CN_HUST_LYH_BASIC_STRING_H

namespace tstd{

template<typename T>
class basic_string {
public:
	using allocator_type	= allocator<T>;
	using data_allocator	= allocator<T>;

	using value_type		= typename allocator_type::value_type;
	using pointer			= typename allocator_type::pointer;
	using const_pointer		= typename allocator_type::const_pointer;
	using reference			= typename allocator_type::reference;
	using const_reference	= typename allocator_type::const_reference;
	using size_type			= typename allocator_type::size_type;
	using difference_type	= typename allocator_type::difference_type;

};
}

#endif	//CN_HUST_LYH_BASIC_STRING_H