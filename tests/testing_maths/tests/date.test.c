#include "date.h"
#include "test.config.h"

TEST_SUITE_BEGIN("Dates")

TEST_CASE_BEGIN("past and future")
{
  STRINGFY_DATE(past, 2026, 4, 9, 9, 5, 5, 50);
  STRINGFY_DATE(present, 2026, 4, 24, 17, 13, 44, 476);
  STRINGFY_DATE(future, 2026, 4, 24, 17, 13, 44, 476);

  TEST_STR_EQ(present, future);
  TEST_STR_GE(present, future);
  TEST_STR_LE(present, future);

  TEST_STR_GE(present, past);
  TEST_STR_GT(present, past);

  TEST_STR_LE(past, future);
  TEST_STR_LT(past, future);
}
TEST_CASE_END

TEST_SUITE_END
