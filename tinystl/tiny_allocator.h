#ifndef CN_HUST_LYH_ALLOCATOR_H
#define CN_HUST_LYH_ALLOCATOR_H

/// <summary>
/// 该头文件包含一个 allocator类 负责得到 
/// </summary>
/// <typeparam name="T"></typeparam>
/// 
/// 

namespace tstd {
template <class T>
class allocator
{
public:
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	static pointer allocate(size_type n);


};

template<typename T>
typename allocator<T>::pointer
allocator<T>::allocate(size_type n) {
	if (n == 0)
		return nullptr;
	//return static_cast<pointer>(::operator new(n * sizeof(value_type)));
	return new T[n];
}
};

#endif // !CN_HUST_LYH_ALLOCATOR_H