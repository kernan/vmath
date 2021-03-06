#include <boost/test/test_case_template.hpp>
#include <boost/test/unit_test.hpp>

#include <array>
#include <stdexcept>
#include <vmath/core/matrix.hpp>
#include "type_lists.hpp"

BOOST_AUTO_TEST_SUITE(matrix2x3)

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, float_types) {
	BOOST_CHECK(sizeof(vmath::core::Matrix<T, 2, 3>) == 3 * 2 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	vmath::core::Matrix<T, 2, 3> M_default;
	BOOST_CHECK_SMALL(M_default[0][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[0][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[1][1], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[2][0], static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(M_default[2][1], static_cast<T>(1e-7));
	// parameterized constructor
	std::array<vmath::core::Vector<T, 2>, 3> data = {{
			vmath::core::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0)),
			vmath::core::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0)),
			vmath::core::Vector<T, 2>(static_cast<T>(5.0), static_cast<T>(6.0))
		}};
	vmath::core::Matrix<T, 2, 3> M_param(data);
	BOOST_CHECK_CLOSE(M_param[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param[2][1], static_cast<T>(6.0), 1e-4f);
	// parameterized constructor
	vmath::core::Vector<T, 2> col1(static_cast<T>(1.0), static_cast<T>(2.0));
	vmath::core::Vector<T, 2> col2(static_cast<T>(3.0), static_cast<T>(4.0));
	vmath::core::Vector<T, 2> col3(static_cast<T>(5.0), static_cast<T>(6.0));
	vmath::core::Matrix<T, 2, 3> M_param2(col1, col2, col3);
	BOOST_CHECK_CLOSE(M_param2[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_param2[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M_copy(M);
	BOOST_CHECK_CLOSE(M_copy[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_copy[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M_move(std::move(M));
	BOOST_CHECK_CLOSE(M_move[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_move[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0] = vmath::core::Vector<T, 2>(static_cast<T>(1.0), static_cast<T>(2.0));
	M[1] = vmath::core::Vector<T, 2>(static_cast<T>(3.0), static_cast<T>(4.0));
	M[2] = vmath::core::Vector<T, 2>(static_cast<T>(5.0), static_cast<T>(6.0));
	BOOST_CHECK_CLOSE(M[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M[2][1], static_cast<T>(6.0), 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(M[3], std::out_of_range);
	BOOST_CHECK_THROW((M[3] = vmath::core::Vector<T, 2>()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M_assign;
	M_assign = M;
	BOOST_CHECK_CLOSE(M_assign[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_assign[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M_neg;
	M_neg = -M;
	BOOST_CHECK_CLOSE(M_neg[0][0], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[0][1], static_cast<T>(-2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][0], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[1][1], static_cast<T>(-4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][0], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_neg[2][1], static_cast<T>(-6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(6.0);
	M2[0][1] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[2][0] = static_cast<T>(2.0);
	M2[2][1] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 2, 3> M_add;
	M_add = M1 + M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], static_cast<T>(7.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_add_eq_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(6.0);
	M2[0][1] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[2][0] = static_cast<T>(2.0);
	M2[2][1] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 2, 3> M_add = M1;
	M_add += M2;
	BOOST_CHECK_CLOSE(M_add[0][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[0][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[1][1], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][0], static_cast<T>(7.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_add[2][1], static_cast<T>(7.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(6.0);
	M2[0][1] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[2][0] = static_cast<T>(2.0);
	M2[2][1] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 2, 3> M_sub;
	M_sub = M1 - M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], static_cast<T>(5.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_sub_eq_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(6.0);
	M2[0][1] = static_cast<T>(5.0);
	M2[1][0] = static_cast<T>(4.0);
	M2[1][1] = static_cast<T>(3.0);
	M2[2][0] = static_cast<T>(2.0);
	M2[2][1] = static_cast<T>(1.0);
	vmath::core::Matrix<T, 2, 3> M_sub = M1;
	M_sub -= M2;
	BOOST_CHECK_CLOSE(M_sub[0][0], static_cast<T>(-5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[0][1], static_cast<T>(-3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][0], static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[1][1], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sub[2][1], static_cast<T>(5.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(matrix_mult_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 3, 2> M_3x2;
	M_3x2[0][0] = static_cast<T>(1.0);
	M_3x2[0][1] = static_cast<T>(2.0);
	M_3x2[0][2] = static_cast<T>(3.0);
	M_3x2[1][0] = static_cast<T>(4.0);
	M_3x2[1][1] = static_cast<T>(5.0);
	M_3x2[1][2] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 3> M_3x3;
	M_3x3[0][0] = static_cast<T>(1.0);
	M_3x3[0][1] = static_cast<T>(2.0);
	M_3x3[0][2] = static_cast<T>(3.0);
	M_3x3[1][0] = static_cast<T>(4.0);
	M_3x3[1][1] = static_cast<T>(5.0);
	M_3x3[1][2] = static_cast<T>(6.0);
	M_3x3[2][0] = static_cast<T>(7.0);
	M_3x3[2][1] = static_cast<T>(8.0);
	M_3x3[2][2] = static_cast<T>(9.0);
	vmath::core::Matrix<T, 3, 4> M_3x4;
	M_3x4[0][0] = static_cast<T>(1.0);
	M_3x4[0][1] = static_cast<T>(2.0);
	M_3x4[0][2] = static_cast<T>(3.0);
	M_3x4[1][0] = static_cast<T>(4.0);
	M_3x4[1][1] = static_cast<T>(5.0);
	M_3x4[1][2] = static_cast<T>(6.0);
	M_3x4[2][0] = static_cast<T>(7.0);
	M_3x4[2][1] = static_cast<T>(8.0);
	M_3x4[2][2] = static_cast<T>(9.0);
	M_3x4[3][0] = static_cast<T>(10.0);
	M_3x4[3][1] = static_cast<T>(11.0);
	M_3x4[3][2] = static_cast<T>(12.0);
	vmath::core::Matrix<T, 2> M_sum2x2;
	M_sum2x2 = M * M_3x2;
	BOOST_CHECK_CLOSE(M_sum2x2[0][0], static_cast<T>(22.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[0][1], static_cast<T>(28.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[1][0], static_cast<T>(49.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x2[1][1], static_cast<T>(64.0), 1e-4f);
	vmath::core::Matrix<T, 2, 3> M_sum2x3;
	M_sum2x3 = M * M_3x3;
	BOOST_CHECK_CLOSE(M_sum2x3[0][0], static_cast<T>(22.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[0][1], static_cast<T>(28.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[1][0], static_cast<T>(49.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[1][1], static_cast<T>(64.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[2][0], static_cast<T>(76.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x3[2][1], static_cast<T>(100.0), 1e-4f);
	vmath::core::Matrix<T, 2, 4> M_sum2x4;
	M_sum2x4 = M * M_3x4;
	BOOST_CHECK_CLOSE(M_sum2x4[0][0], static_cast<T>(22.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[0][1], static_cast<T>(28.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[1][0], static_cast<T>(49.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[1][1], static_cast<T>(64.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[2][0], static_cast<T>(76.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[2][1], static_cast<T>(100.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[3][0], static_cast<T>(103.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_sum2x4[3][1], static_cast<T>(136.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 2, 3> M_mult;
	M_mult = M * s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], static_cast<T>(12.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 2, 3> M_mult = M;
	M_mult *= s;
	BOOST_CHECK_CLOSE(M_mult[0][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[0][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][0], static_cast<T>(6.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[1][1], static_cast<T>(8.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][0], static_cast<T>(10.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_mult[2][1], static_cast<T>(12.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(6.0);
	M[1][1] = static_cast<T>(8.0);
	M[2][0] = static_cast<T>(10.0);
	M[2][1] = static_cast<T>(12.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 2, 3> M_div;
	M_div = M / s;
	BOOST_CHECK_CLOSE(M_div[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(2.0);
	M[0][1] = static_cast<T>(4.0);
	M[1][0] = static_cast<T>(6.0);
	M[1][1] = static_cast<T>(8.0);
	M[2][0] = static_cast<T>(10.0);
	M[2][1] = static_cast<T>(12.0);
	T s = static_cast<T>(2.0);
	vmath::core::Matrix<T, 2, 3> M_div = M;
	M_div /= s;
	BOOST_CHECK_CLOSE(M_div[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[0][1], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][0], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][0], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_div[2][1], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(transpose, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M;
	M[0][0] = static_cast<T>(1.0);
	M[0][1] = static_cast<T>(2.0);
	M[1][0] = static_cast<T>(3.0);
	M[1][1] = static_cast<T>(4.0);
	M[2][0] = static_cast<T>(5.0);
	M[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 3, 2> M_trans;
	M_trans = M.transpose();
	BOOST_CHECK_CLOSE(M_trans[0][0], static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][1], static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[0][2], static_cast<T>(5.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][0], static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][1], static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(M_trans[1][2], static_cast<T>(6.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[1][0] = static_cast<T>(3.0);
	M2[1][1] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(5.0);
	M2[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M3;
	M3[0][0] = static_cast<T>(6.0);
	M3[0][1] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[2][0] = static_cast<T>(2.0);
	M3[2][1] = static_cast<T>(1.0);
	BOOST_CHECK(M1.equals(M2));
	BOOST_CHECK(!M1.equals(M3));
	BOOST_CHECK(!M2.equals(M3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_specify_ulp, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[1][0] = static_cast<T>(3.0);
	M2[1][1] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(5.0);
	M2[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M3;
	M3[0][0] = static_cast<T>(6.0);
	M3[0][1] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[2][0] = static_cast<T>(2.0);
	M3[2][1] = static_cast<T>(1.0);
	BOOST_CHECK(M1.equals(M2, 3));
	BOOST_CHECK(!M1.equals(M3, 3));
	BOOST_CHECK(!M2.equals(M3, 3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op, T, float_types) {
	vmath::core::Matrix<T, 2, 3> M1;
	M1[0][0] = static_cast<T>(1.0);
	M1[0][1] = static_cast<T>(2.0);
	M1[1][0] = static_cast<T>(3.0);
	M1[1][1] = static_cast<T>(4.0);
	M1[2][0] = static_cast<T>(5.0);
	M1[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M2;
	M2[0][0] = static_cast<T>(1.0);
	M2[0][1] = static_cast<T>(2.0);
	M2[1][0] = static_cast<T>(3.0);
	M2[1][1] = static_cast<T>(4.0);
	M2[2][0] = static_cast<T>(5.0);
	M2[2][1] = static_cast<T>(6.0);
	vmath::core::Matrix<T, 2, 3> M3;
	M3[0][0] = static_cast<T>(6.0);
	M3[0][1] = static_cast<T>(5.0);
	M3[1][0] = static_cast<T>(4.0);
	M3[1][1] = static_cast<T>(3.0);
	M3[2][0] = static_cast<T>(2.0);
	M3[2][1] = static_cast<T>(1.0);
	BOOST_CHECK(M1 == M2);
	BOOST_CHECK(M1 != M3);
	BOOST_CHECK(M2 != M3);
}

BOOST_AUTO_TEST_SUITE_END()
