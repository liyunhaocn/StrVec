#ifndef CN_HUST_LYH_VECTOR_H
#define CN_HUST_LYH_VECTOR_H

#include <iostream>

namespace util {

	class Vector {
	public:
		Vector();
		Vector(size_t _len);
		Vector(size_t _len, int val);

		Vector(const Vector& _Right) {
			
			_data;
		}

		int& operator [](size_t index);

		void push_back(const int& val);

		size_t capacity();

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

