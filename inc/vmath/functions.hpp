#ifndef VMATH_FUNCIONS_HPP
#define VMATH_FUNCIONS_HPP

#include <cmath>
#include <type_traits>

namespace vmath {

const long double PI = std::acos(-1.0L);

/*!
 * \brief Determine if two float are equivalent within a given tolerance
 * \param[in] a Float to compare
 * \param[in] b Float to compare
 * \param[in] ulp The desired floating point precision in ULPs (units in the last place), default 2
 * \return True if they are equivalent, otherwise false
 */
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
bool equals(const T a, const T b, const int ulp=2);

/*!
 * \brief Convert degrees to radians
 * \param[in] degrees Degrees to convert
 * \return The given degrees in radians
 */
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T radians(const T degrees);

/*!
 * \brief Convert radians to degrees
 * \param[in] radians Radians to convert
 * \return The given radians in degrees
 */
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T degrees(const T radians);

/*!
 * \brief Clamp into a range
 * \param[in] s Scalar to clamp
 * \param[in] lo Lowest number included in the range
 * \param[in] hi Highest number included in the range
 * \return Clamped scalar
 */
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T clamp(const T s, const T lo, const T hi);

/*!
 * \brief Linearly interpolate scalars
 * \param[in] s Start value
 * \param[in] e End value
 * \param[in] t Amount to interpolate by
 * \return Interpolated scalar
 */
template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
T lerp(const T s, const T e, const T t);

}

#include <vmath/functions.inl>

#endif
