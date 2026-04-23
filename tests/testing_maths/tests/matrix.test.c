#include "test.config.h"
#include "matrix.h"

TEST_SUITE_BEGIN("Matrix")

TEST_CASE_BEGIN("to be equal or not")
{
  const struct matrix a = {1, 1, 1, 0};
  const struct matrix b = {1, 1, 0, 1};
  const struct matrix c = {1, 1, 1, 0};

  TEST_STRUCT_EQ(a, b);
  TEST_STRUCT_EQ(a, c);
  TEST_STRUCT_EQ(b, c);
}
TEST_CASE_END

TEST_SUITE_END
