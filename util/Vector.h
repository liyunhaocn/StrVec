#ifndef CN_HUST_LYH_VECTOR_H
#define CN_HUST_LYH_VECTOR_H

#include <iostream>

namespace util {
	
	//template<typename T>
	class Vector {
	public:

		using value_type	= int;
		using reference		= value_type&;
		using pointer		= value_type*;
		using size_type		= size_t;

		size_t capacity();
		size_t size() const;

		int& operator [](size_t index) const;

		Vector();
		Vector(size_t _len);
		Vector(size_t _len, int val);
		Vector(const Vector& lval);

		void push_back(const int& val);

		void show();

		~Vector();
		
	private:

		int* _data;
		size_t _len;
		size_t _cap;

		bool reAlloc(const int len);
	};

}



#endif // !CN_HUST_LYH_VECTOR_H

