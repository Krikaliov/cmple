#include "cmple.h"
#include "fact.h"

/*===========*/
TEST_CASE_BEGIN
/*===========*/

ASSERT_EQ(fact_recursive(-1)   , -1);
ASSERT_EQ(fact_recursive(-1001), -1);

ASSERT_EQ(fact_recursive(0), 1);
ASSERT_EQ(fact_recursive(1), 1);
ASSERT_EQ(fact_recursive(2), 2);

ASSERT_EQ(fact_recursive(3), 6);
ASSERT_EQ(fact_recursive(4), 24);
ASSERT_EQ(fact_recursive(5), 120);
ASSERT_EQ(fact_recursive(6), 720);
ASSERT_EQ(fact_recursive(7), 5040);


ASSERT_EQ(fact_imperative(-1)   , -1);
ASSERT_EQ(fact_imperative(-1001), -1);

ASSERT_EQ(fact_imperative(0), 1);
ASSERT_EQ(fact_imperative(1), 1);
ASSERT_EQ(fact_imperative(2), 2);

ASSERT_EQ(fact_imperative(3), 6);
ASSERT_EQ(fact_imperative(4), 24);
ASSERT_EQ(fact_imperative(5), 120);
ASSERT_EQ(fact_imperative(6), 720);
ASSERT_EQ(fact_imperative(7), 5040);

/*=========*/
TEST_CASE_END
/*=========*/
