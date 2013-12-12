#ifndef MATH_CORE_SWIZZLE_SWIZZLE4_HPP
#define MATH_CORE_SWIZZLE_SWIZZLE4_HPP

#include "swizzle.hpp"

namespace math {
namespace core {

template<typename T, std::size_t N>
class Vector;

/**
 * @class Swizzle4
 * @tparam T Storage type.
 * @tparam N Storage size.
 * @tparam E1 Index of first element.
 * @tparam E2 Index of second element.
 * @tparam E3 Index of third element.
 * @tparam E4 Index of fourth element.
 * A 4-dimensional vector swizzle.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2, std::size_t E3, std::size_t E4>
class Swizzle4 : public Swizzle<T, N> {
private:
	inline Vector<T, 4> to_vector4(void) const;
public:
	operator Vector<T, 4>(void);

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator=(const Vector<T, 4>&);

	Vector<T, 4> operator+(const Vector<T, 4>&) const;

	Vector<T, 4> operator-(void) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator+=(const Vector<T, 4>&);

	Vector<T, 4> operator-(const Vector<T, 4>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator-=(const Vector<T, 4>&);

	Vector<T, 4> operator*(const Vector<T, 4>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator*=(const Vector<T, 4>&);

	Vector<T, 4> operator/(const Vector<T, 4>&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator/=(const Vector<T, 4>&);

	Vector<T, 4> operator*(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator*=(const T&);

	Vector<T, 4> operator/(const T&) const;

	template<typename U = T,
		typename = typename std::enable_if<is_assignable_swizzle<4, E1, E2, E3, E4>::value
		&& std::is_same<T, U>::value>::type>
	Vector<T, 4>& operator/=(const T&);

	bool operator==(const Vector<T, 4>&) const;
	bool operator!=(const Vector<T, 4>&) const;

#if defined(MATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS)
	T getE1(void) { return this->data[E1]; }
	T getE2(void) { return this->data[E2]; }
	T getE3(void) { return this->data[E3]; }
	T getE4(void) { return this->data[E4]; }
#endif
};

}
}

#include "swizzle4.inl"

#endif
