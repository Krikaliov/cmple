#define N 5
#include "test.config.h"

TEST_SUITE_BEGIN("Arrays")

TEST_CASE_BEGIN("to be equal or not")
{
  const int u[N] = {1, 4, 9, 16, 25};
  const int v[N] = {1, 4, 9, 16, 24};

  TEST_ARRAY_EQ(u, v, N * sizeof(int));
}
TEST_CASE_END

TEST_SUITE_END
