#include "test.config.h"
#include "matrix.h"

TEST_SUITE_BEGIN("Matrix")

TEST_CASE_BEGIN("to be equal or not")
{
  const struct matrix a = {1, 1, 1, 0};
  const struct matrix b = {1, 1, 0, 1};
  const struct matrix c = {1, 1, 1, 0};

  TEST_EXPR(!matrix_eq(a, b));
  TEST_EXPR(matrix_eq(a, c));
}
TEST_CASE_END

TEST_CASE_BEGIN("determinant and inverse")
{
  const struct matrix zero = matrix_zero();
  const struct matrix id_2 = matrix_id();

  const struct matrix u = {4, 8, -3, -6};
  const struct matrix v = {4, -8, 3, 6};

  TEST_EQ(matrix_det(u), 0);
  TEST_EQ(matrix_det(v), 48);

  const struct matrix u_inv = matrix_inverse(u);
  const struct matrix v_inv = matrix_inverse(v);

  TEST_NE(pop_matrix_last_errno(), 0);
  TEST_EQ(pop_matrix_last_errno(), 0);

  TEST_EXPR(matrix_eq(u_inv, zero));

  const struct matrix v_v_inv = matrix_mul(v, v_inv);

  TEST_EXPR(matrix_eq(v_v_inv, id_2));
}
TEST_CASE_END

TEST_SUITE_END
