#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#define ON_TEST_SUITE_BEGIN
#define ON_TEST_SUITE_END

#define ON_TEST_CASE_BEGIN
#define ON_TEST_CASE_END

#define ON_TEST_FAILURE_FILE_LINE

#define ON_TEST_EXPR_FAILURE(expr)

#define ON_TEST_EQ_FAILURE(a,b,t)
#define ON_TEST_NE_FAILURE(a,b,t)
#define ON_TEST_LE_FAILURE(a,b,t)
#define ON_TEST_LT_FAILURE(a,b,t)
#define ON_TEST_GE_FAILURE(a,b,t)
#define ON_TEST_GT_FAILURE(a,b,t)

#define ON_TEST_STR_EQ_FAILURE(x,y)
#define ON_TEST_STR_NE_FAILURE(x,y)
#define ON_TEST_STR_LE_FAILURE(x,y)
#define ON_TEST_STR_LT_FAILURE(x,y)
#define ON_TEST_STR_GE_FAILURE(x,y)
#define ON_TEST_STR_GT_FAILURE(x,y)

#define ON_TEST_ARRAY_EQ_FAILURE(x,y,n)
#define ON_TEST_ARRAY_NE_FAILURE(x,y,n)

#include "cmple.h"

#endif // TEST_CONFIG_H
