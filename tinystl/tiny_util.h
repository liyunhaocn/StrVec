#ifndef CN_HUST_LYH_UTIL_H
#define CN_HUST_LYH_UTIL_H

#include <iostream>
#include <string>

namespace util {

	template<typename T, typename ...U>
	void println(T v, U ...u) {
		if constexpr (sizeof...(U) == 0) {
			std::cout << v << std::endl;
		}
		else {
			std::cout << v << ", ";
			println(u...);
		}
	}

	int print(int n, ...)
	{
		int i, val;
		va_list vl;
		va_start(vl, n);

		for (i = 0; i < n; i++)
		{
			val = va_arg(vl, int);
			std::cout << val << ", ";
		}
		std::cout << std::endl;
		va_end(vl);
		return 0;
	}

	template<typename T>
	bool construct(T* ptr,T val) {
		println("construct: ",typeid(T).name());
		println("ptr: ",ptr);
		::new(ptr)T(val);
		return true;
	}

	template<typename T>
	std::string getNameOfT(T t) {
		return typeid(T).name();
	}
}
#endif //CN_HUST_LYH_UTIL_H
