#include "test.config.h"
#include "fact.h"

TEST_SUITE_BEGIN("Factorial")

TEST_CASE_BEGIN("recursive function")
{
  TEST_EQ(fact_recursive(-1)   , -1);
  TEST_EQ(fact_recursive(-1001), -1);

  TEST_EQ(fact_recursive(0), 1);
  TEST_EQ(fact_recursive(1), 1);
  TEST_EQ(fact_recursive(2), 2);

  TEST_EQ(fact_recursive(3), 6);
  TEST_EQ(fact_recursive(4), 24);
  TEST_EQ(fact_recursive(5), 120);
  TEST_EQ(fact_recursive(6), 720);
  TEST_EQ(fact_recursive(7), 5040);
}
TEST_CASE_END

TEST_CASE_BEGIN("imperative function")
{
  TEST_EQ(fact_imperative(-1)   , -1);
  TEST_EQ(fact_imperative(-1001), -1);

  TEST_EQ(fact_imperative(0), 1);
  TEST_EQ(fact_imperative(1), 1);
  TEST_EQ(fact_imperative(2), 2);

  TEST_EQ(fact_imperative(3), 6);
  TEST_EQ(fact_imperative(4), 24);
  TEST_EQ(fact_imperative(5), 120);
  TEST_EQ(fact_imperative(6), 720);
  TEST_EQ(fact_imperative(7), 5040);
}
TEST_CASE_END

TEST_SUITE_END
