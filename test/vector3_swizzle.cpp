#define BOOST_TEST_MODULE vector3_swizzle
#include "boost_test_config.hpp"

#include <vmath/vector3.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, floating_point_types) {
	// TODO
}

// TODO mag
// TODO mag2
// TODO normal
// TODO normalize
// TODO dot
// TODO cross
// TODO lerp
// TODO reflect
// TODO refract
// TODO equals
// TODO equals_op_int
// TODO equals_op_float

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	auto a = v + v.xxx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(121.01), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(1.92), TOLERANCE);
	auto b = v.xxx + v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(121.01), TOLERANCE);
	BOOST_CHECK_CLOSE(b.z, static_cast<T>(1.92), TOLERANCE);
	auto c = v.xxx + v.xxx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(40.24), TOLERANCE);
	BOOST_CHECK_CLOSE(c.z, static_cast<T>(40.24), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	auto a = v - v.xxx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(0.0), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(80.77), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(-38.32), TOLERANCE);
	auto b = v.xxx - v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(0.0), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(-80.77), TOLERANCE);
	BOOST_CHECK_CLOSE(b.z, static_cast<T>(38.32), TOLERANCE);
	auto c = v.xxx - v.xxx;
	BOOST_CHECK_SMALL(c.x, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(c.y, static_cast<T>(ZERO));
	BOOST_CHECK_SMALL(c.z, static_cast<T>(ZERO));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	auto a = v * v.xxx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(2029.9068), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(-366.184), TOLERANCE);
	auto b = v.xxx * v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(2029.9068), TOLERANCE);
	BOOST_CHECK_CLOSE(b.z, static_cast<T>(-366.184), TOLERANCE);
	auto c = v.xxx * v.xxx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(404.8144), TOLERANCE);
	BOOST_CHECK_CLOSE(c.z, static_cast<T>(404.8144), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	auto a = v / v.xxx;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(5.01441351888668), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(-0.904572564612326), TOLERANCE);
	auto b = v.xxx / v;
	BOOST_CHECK_CLOSE(b.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(b.y, static_cast<T>(0.1994251164634751), TOLERANCE);
	BOOST_CHECK_CLOSE(b.z, static_cast<T>(-1.105494505494505), TOLERANCE);
	auto c = v.xxx / v.xxx;
	BOOST_CHECK_CLOSE(c.x, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(1.0), TOLERANCE);
	BOOST_CHECK_CLOSE(c.y, static_cast<T>(1.0), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	T s = static_cast<T>(3.2);
	auto a = v.yzx * s;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(322.848), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(-58.24), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(64.384), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, floating_point_types) {
	// TODO
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	T s = static_cast<T>(3.2);
	auto a = v.yzx / s;
	BOOST_CHECK_CLOSE(a.x, static_cast<T>(31.528125), TOLERANCE);
	BOOST_CHECK_CLOSE(a.y, static_cast<T>(-5.6875), TOLERANCE);
	BOOST_CHECK_CLOSE(a.z, static_cast<T>(6.2875), TOLERANCE);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, floating_point_types) {
	// TODO
}

#define CHECK_VECTOR3_SWIZZLE2(E1, E2) \
	BOOST_CHECK(sizeof(v. E1 ## E2) == 3 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 [1], v. E2, TOLERANCE);

#define CHECK_VECTOR3_SWIZZLE2_EXISTS(E1, E2) \
	v. E1 ## E2;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle2, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	CHECK_VECTOR3_SWIZZLE2(x, x)
	CHECK_VECTOR3_SWIZZLE2(x, y)
	CHECK_VECTOR3_SWIZZLE2(x, z)
	CHECK_VECTOR3_SWIZZLE2(y, x)
	CHECK_VECTOR3_SWIZZLE2(y, y)
	CHECK_VECTOR3_SWIZZLE2(y, z)
	CHECK_VECTOR3_SWIZZLE2(z, x)
	CHECK_VECTOR3_SWIZZLE2(z, y)
	CHECK_VECTOR3_SWIZZLE2(z, z)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(s, s)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(s, t)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(s, p)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(t, s)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(t, t)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(t, p)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(p, s)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(p, t)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(p, p)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(r, r)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(r, g)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(r, b)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(g, r)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(g, g)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(g, b)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(b, r)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(b, g)
	CHECK_VECTOR3_SWIZZLE2_EXISTS(b, b)
}

#define CHECK_VECTOR3_SWIZZLE3(E1, E2, E3) \
	BOOST_CHECK(sizeof(v. E1 ## E2 ## E3) == 3 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [1], v. E2, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 [2], v. E3, TOLERANCE);

#define CHECK_VECTOR3_SWIZZLE3_EXISTS(E1, E2, E3) \
	v. E1 ## E2 ## E3;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle3, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	CHECK_VECTOR3_SWIZZLE3(x, x, x)
	CHECK_VECTOR3_SWIZZLE3(x, x, y)
	CHECK_VECTOR3_SWIZZLE3(x, x, z)
	CHECK_VECTOR3_SWIZZLE3(x, y, x)
	CHECK_VECTOR3_SWIZZLE3(x, y, y)
	CHECK_VECTOR3_SWIZZLE3(x, y, z)
	CHECK_VECTOR3_SWIZZLE3(x, z, x)
	CHECK_VECTOR3_SWIZZLE3(x, z, y)
	CHECK_VECTOR3_SWIZZLE3(x, z, z)
	CHECK_VECTOR3_SWIZZLE3(y, x, x)
	CHECK_VECTOR3_SWIZZLE3(y, x, y)
	CHECK_VECTOR3_SWIZZLE3(y, x, z)
	CHECK_VECTOR3_SWIZZLE3(y, y, x)
	CHECK_VECTOR3_SWIZZLE3(y, y, y)
	CHECK_VECTOR3_SWIZZLE3(y, y, z)
	CHECK_VECTOR3_SWIZZLE3(y, z, x)
	CHECK_VECTOR3_SWIZZLE3(y, z, y)
	CHECK_VECTOR3_SWIZZLE3(y, z, z)
	CHECK_VECTOR3_SWIZZLE3(z, x, x)
	CHECK_VECTOR3_SWIZZLE3(z, x, y)
	CHECK_VECTOR3_SWIZZLE3(z, x, z)
	CHECK_VECTOR3_SWIZZLE3(z, y, x)
	CHECK_VECTOR3_SWIZZLE3(z, y, y)
	CHECK_VECTOR3_SWIZZLE3(z, y, z)
	CHECK_VECTOR3_SWIZZLE3(z, z, x)
	CHECK_VECTOR3_SWIZZLE3(z, z, y)
	CHECK_VECTOR3_SWIZZLE3(z, z, z)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, s, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, s, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, s, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, t, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, t, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, t, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, p, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, p, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(s, p, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, s, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, s, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, s, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, t, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, t, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, t, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, p, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, p, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(t, p, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, s, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, s, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, s, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, t, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, t, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, t, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, p, s)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, p, t)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(p, p, p)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, r, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, r, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, r, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, g, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, g, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, g, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, b, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, b, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(r, b, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, r, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, r, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, r, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, g, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, g, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, g, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, b, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, b, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(g, b, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, r, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, r, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, r, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, g, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, g, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, g, b)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, b, r)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, b, g)
	CHECK_VECTOR3_SWIZZLE3_EXISTS(b, b, b)
}

#define CHECK_VECTOR3_SWIZZLE4(E1, E2, E3, E4) \
	BOOST_CHECK(sizeof(v. E1 ## E2 ## E3 ## E4) == 3 * sizeof(T)); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [0], v. E1, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [1], v. E2, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [2], v. E3, TOLERANCE); \
	BOOST_CHECK_CLOSE(v. E1 ## E2 ## E3 ## E4 [3], v. E4, TOLERANCE);

#define CHECK_VECTOR3_SWIZZLE4_EXISTS(E1, E2, E3, E4) \
	v. E1 ## E2 ## E3 ## E4;

BOOST_AUTO_TEST_CASE_TEMPLATE(swizzle4, T, floating_point_types) {
	vmath::Vector<T, 3> v(static_cast<T>(20.12), static_cast<T>(100.89), static_cast<T>(-18.2));
	CHECK_VECTOR3_SWIZZLE4(x, x, x, x)
	CHECK_VECTOR3_SWIZZLE4(x, x, x, y)
	CHECK_VECTOR3_SWIZZLE4(x, x, x, z)
	CHECK_VECTOR3_SWIZZLE4(x, x, y, x)
	CHECK_VECTOR3_SWIZZLE4(x, x, y, y)
	CHECK_VECTOR3_SWIZZLE4(x, x, y, z)
	CHECK_VECTOR3_SWIZZLE4(x, x, z, x)
	CHECK_VECTOR3_SWIZZLE4(x, x, z, y)
	CHECK_VECTOR3_SWIZZLE4(x, x, z, z)
	CHECK_VECTOR3_SWIZZLE4(x, y, x, x)
	CHECK_VECTOR3_SWIZZLE4(x, y, x, y)
	CHECK_VECTOR3_SWIZZLE4(x, y, x, z)
	CHECK_VECTOR3_SWIZZLE4(x, y, y, x)
	CHECK_VECTOR3_SWIZZLE4(x, y, y, y)
	CHECK_VECTOR3_SWIZZLE4(x, y, y, z)
	CHECK_VECTOR3_SWIZZLE4(x, y, z, x)
	CHECK_VECTOR3_SWIZZLE4(x, y, z, y)
	CHECK_VECTOR3_SWIZZLE4(x, y, z, z)
	CHECK_VECTOR3_SWIZZLE4(x, z, x, x)
	CHECK_VECTOR3_SWIZZLE4(x, z, x, y)
	CHECK_VECTOR3_SWIZZLE4(x, z, x, z)
	CHECK_VECTOR3_SWIZZLE4(x, z, y, x)
	CHECK_VECTOR3_SWIZZLE4(x, z, y, y)
	CHECK_VECTOR3_SWIZZLE4(x, z, y, z)
	CHECK_VECTOR3_SWIZZLE4(x, z, z, x)
	CHECK_VECTOR3_SWIZZLE4(x, z, z, y)
	CHECK_VECTOR3_SWIZZLE4(x, z, z, z)
	CHECK_VECTOR3_SWIZZLE4(y, x, x, x)
	CHECK_VECTOR3_SWIZZLE4(y, x, x, y)
	CHECK_VECTOR3_SWIZZLE4(y, x, x, z)
	CHECK_VECTOR3_SWIZZLE4(y, x, y, x)
	CHECK_VECTOR3_SWIZZLE4(y, x, y, y)
	CHECK_VECTOR3_SWIZZLE4(y, x, y, z)
	CHECK_VECTOR3_SWIZZLE4(y, x, z, x)
	CHECK_VECTOR3_SWIZZLE4(y, x, z, y)
	CHECK_VECTOR3_SWIZZLE4(y, x, z, z)
	CHECK_VECTOR3_SWIZZLE4(y, y, x, x)
	CHECK_VECTOR3_SWIZZLE4(y, y, x, y)
	CHECK_VECTOR3_SWIZZLE4(y, y, x, z)
	CHECK_VECTOR3_SWIZZLE4(y, y, y, x)
	CHECK_VECTOR3_SWIZZLE4(y, y, y, y)
	CHECK_VECTOR3_SWIZZLE4(y, y, y, z)
	CHECK_VECTOR3_SWIZZLE4(y, y, z, x)
	CHECK_VECTOR3_SWIZZLE4(y, y, z, y)
	CHECK_VECTOR3_SWIZZLE4(y, y, z, z)
	CHECK_VECTOR3_SWIZZLE4(y, z, x, x)
	CHECK_VECTOR3_SWIZZLE4(y, z, x, y)
	CHECK_VECTOR3_SWIZZLE4(y, z, x, z)
	CHECK_VECTOR3_SWIZZLE4(y, z, y, x)
	CHECK_VECTOR3_SWIZZLE4(y, z, y, y)
	CHECK_VECTOR3_SWIZZLE4(y, z, y, z)
	CHECK_VECTOR3_SWIZZLE4(y, z, z, x)
	CHECK_VECTOR3_SWIZZLE4(y, z, z, y)
	CHECK_VECTOR3_SWIZZLE4(y, z, z, z)
	CHECK_VECTOR3_SWIZZLE4(z, x, x, x)
	CHECK_VECTOR3_SWIZZLE4(z, x, x, y)
	CHECK_VECTOR3_SWIZZLE4(z, x, x, z)
	CHECK_VECTOR3_SWIZZLE4(z, x, y, x)
	CHECK_VECTOR3_SWIZZLE4(z, x, y, y)
	CHECK_VECTOR3_SWIZZLE4(z, x, y, z)
	CHECK_VECTOR3_SWIZZLE4(z, x, z, x)
	CHECK_VECTOR3_SWIZZLE4(z, x, z, y)
	CHECK_VECTOR3_SWIZZLE4(z, x, z, z)
	CHECK_VECTOR3_SWIZZLE4(z, y, x, x)
	CHECK_VECTOR3_SWIZZLE4(z, y, x, y)
	CHECK_VECTOR3_SWIZZLE4(z, y, x, z)
	CHECK_VECTOR3_SWIZZLE4(z, y, y, x)
	CHECK_VECTOR3_SWIZZLE4(z, y, y, y)
	CHECK_VECTOR3_SWIZZLE4(z, y, y, z)
	CHECK_VECTOR3_SWIZZLE4(z, y, z, x)
	CHECK_VECTOR3_SWIZZLE4(z, y, z, y)
	CHECK_VECTOR3_SWIZZLE4(z, y, z, z)
	CHECK_VECTOR3_SWIZZLE4(z, z, x, x)
	CHECK_VECTOR3_SWIZZLE4(z, z, x, y)
	CHECK_VECTOR3_SWIZZLE4(z, z, x, z)
	CHECK_VECTOR3_SWIZZLE4(z, z, y, x)
	CHECK_VECTOR3_SWIZZLE4(z, z, y, y)
	CHECK_VECTOR3_SWIZZLE4(z, z, y, z)
	CHECK_VECTOR3_SWIZZLE4(z, z, z, x)
	CHECK_VECTOR3_SWIZZLE4(z, z, z, y)
	CHECK_VECTOR3_SWIZZLE4(z, z, z, z)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, s, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, t, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(s, p, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, s, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, t, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(t, p, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, s, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, t, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, s, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, s, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, s, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, t, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, t, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, t, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, p, s)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, p, t)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(p, p, p, p)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, r, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, g, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(r, b, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, r, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, g, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(g, b, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, r, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, g, b, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, r, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, r, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, r, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, g, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, g, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, g, b)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, b, r)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, b, g)
	CHECK_VECTOR3_SWIZZLE4_EXISTS(b, b, b, b)
}
