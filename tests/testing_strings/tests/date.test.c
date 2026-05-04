#include "date.h"
#include "test.config.h"

TEST_SUITE_BEGIN("Dates")

TEST_CASE_BEGIN("past and future")
{
  char past[DATE_MAXLENGTH];
  char present[DATE_MAXLENGTH];
  char future[DATE_MAXLENGTH];

  format_date(past, 2026, 4, 9, 9, 5, 5, 50);
  format_date(present, 2026, 4, 24, 17, 13, 44, 476);
  format_date(future, 2026, 4, 24, 17, 13, 44, 476);

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
