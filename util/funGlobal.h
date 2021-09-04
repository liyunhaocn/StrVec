#ifndef CN_HUST_LYH_FUNGOBAL_H
#define CN_HUST_LYH_FUNGOBAL_H

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

}
#endif //CN_HUST_LYH_FUNGOBAL_H
