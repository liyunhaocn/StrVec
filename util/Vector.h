#ifndef CN_HUST_LYH_VECTOR_H
#define CN_HUST_LYH_VECTOR_H

#include <iostream>

namespace util {
	
	//template<typename T>
	class Vector {
	public:

		using value_type		= int;
		using reference			= value_type&;
		using pointer			= value_type*;
		using size_type			= size_t;
		using iterator			= value_type*;
		using const_iterator	= value_type*;

		size_t capacity();
		size_t size() const;

		int& operator [](size_t index) const;

		Vector();
		Vector(size_type n);
		Vector(size_type n, value_type val);
		Vector(const Vector& lval);

		Vector(Vector&& rval) noexcept;

		Vector& operator = (const Vector& lval);
		Vector& operator = (Vector&& rval) noexcept;

		void push_back(const value_type& val);

		void show();

		~Vector();
		

		iterator begin() {
			return _begin;
		}
		
		iterator end() {
			return _end;
		}

	private:

		iterator _begin;
		iterator _end;
		iterator _cap;

		pointer allocate(size_type n);
	};

}



#endif // !CN_HUST_LYH_VECTOR_H

