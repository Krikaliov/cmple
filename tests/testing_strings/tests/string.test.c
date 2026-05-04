#include "test.config.h"

TEST_SUITE_BEGIN("Strings")

TEST_CASE_BEGIN("to be equal or not")
{
  const char string1[] = "Hello world!";
  const char string2[] = "Hello world.";
  const char string3[] = "Hello world!";
  const char string4[] = "hello world!";

  TEST_STR_NE(string1, string2);
  TEST_STR_EQ(string1, string3);
  TEST_STR_NE(string1, string4);

  TEST_STR_NE(string2, string3);
  TEST_STR_NE(string2, string4);
  
  TEST_STR_NE(string3, string4);
}
TEST_CASE_END

TEST_SUITE_END
