#ifndef CMPLE_H
#define CMPLE_H

/**
 * cmple.h - the lightest header-only library for unit testing your programs in C
 * 
 * Copyright (c) 2026 Krikaliov
 */

/**
 * TODO:
 * - CI/CD process via Github Actions
 * - Complete README.md
 * - Web site for the documentation
 * THEN:
 * --> Launch first release
 */

/**
 * FUTURE:
 * - Thread-safe tests
 * - Mocking functions or jumps
 * - Asynchronous performance tests
 */

#ifdef __cplusplus
extern "C" {
#endif

/****************/
/* CMPLE KERNEL */
/****************/
#ifndef NULL
#define NULL ((void*)0)
#endif

#define RAW_PASTE(x,y) x##y
#define PASTE(x,y) RAW_PASTE(x,y)

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef CMPLE_SIZE_T
#define CMPLE_SIZE_T unsigned long
#endif

#ifndef CMPLE_INLINE
#define CMPLE_INLINE static inline
#endif

CMPLE_INLINE int _cmple_memcmp(const void* u, const void* v, const CMPLE_SIZE_T n)
{
  CMPLE_SIZE_T i = 0;
  const unsigned char* pu = (const unsigned char*) u;
  const unsigned char* pv = (const unsigned char*) v;
  while (i < n && (pu[i] == pv[i])) i++;
  return i < n ? (int)(pu[i] - pv[i]) : 0;
}
#ifndef CMPLE_MEMCMP
#define CMPLE_MEMCMP(u,v,n) _cmple_memcmp(u,v,n)
#endif

CMPLE_INLINE CMPLE_SIZE_T _cmple_strlen(const char* x)
{
  const char* start = x;
  while (*x) x++;
  return (CMPLE_SIZE_T)(x - start);
}
#ifndef CMPLE_STRLEN
#define CMPLE_STRLEN(x) _cmple_strlen(x)
#endif

CMPLE_INLINE int _cmple_strcmp(const char* x, const char* y)
{
  while (*x && (*x == *y)) { x++; y++; };
  return (int)(*(unsigned char*)x - *(unsigned char*)y);
}
#ifndef CMPLE_STRCMP
#define CMPLE_STRCMP(x,y) _cmple_strcmp(x,y)
#endif

/*********************/
/* CMPLE TEST KERNEL */
/*********************/
#define TEST_NAME_LENGTH 256
#define TEST_NEW_CASE_VARNAME PASTE(test_case, __LINE__)

struct test_case_status
{
  const char name[TEST_NAME_LENGTH];
  unsigned int failed_tests;
  struct test_case_status* next_case;
};

struct test_suite_status
{
  const char name[TEST_NAME_LENGTH];
  struct test_case_status* first_case;
  unsigned int test_case_count;
  unsigned int failed_test_case_count;
  unsigned int failed_test_count;
};

/*************************/
/* TEST PUBLIC CONSTANTS */
/*************************/

/**
 * Name of the test suite
 * @param type string
 * @param scope inside test suite, inside and/or outside any test case
 */
#define TEST_VAR_SUITE_NAME test_suite.name

/**
 * Number of test cases in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_CASE_COUNT test_suite.test_case_count

/**
 * Number of test cases that passed in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_PASSED_CASE_COUNT test_suite.test_case_count - test_suite.failed_test_case_count

/**
 * Number of test cases that failed in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_FAILED_CASE_COUNT test_suite.failed_test_case_count

/**
 * Number of total fails in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of tests that have run before the call of this constant.
 */
#define TEST_VAR_TOTAL_FAILURE_COUNT test_suite.failed_test_count

/**
 * Name of the current test case
 * @param type string
 * @param scope only inside test case
 */
#define TEST_VAR_CURRENT_CASE_NAME current_case->name

/**
 * Number of tests that failed in this test case
 * @param type unsigned int
 * @param scope only inside test case
 * @note This only takes account of tests that have run before the call of this constant inside the test case.
 */
#define TEST_VAR_CURRENT_CASE_FAILS current_case->failed_tests

/******************/
/* TEST FUNCTIONS */
/******************/
#ifndef ON_TEST_SUITE_BEGIN
#define ON_TEST_SUITE_BEGIN \
  fprintf(stdout, "[%s] Starting test suite...\n", test_suite.name)
#endif

#define TEST_SUITE_BEGIN(name) \
int main(int argc, char** argv) { \
  struct test_suite_status test_suite = (struct test_suite_status) { name, NULL, 0, 0, 0 }; \
  struct test_case_status* current_case = NULL; \
  ON_TEST_SUITE_BEGIN;

#ifndef ON_TEST_SUITE_END
#define ON_TEST_SUITE_END \
  fprintf(stdout, "[%s] Test suite finished.\n", test_suite.name); \
  fprintf(stdout, "[%s] >>> Passed test cases: %d/%d (%.1f%%)\n", \
    test_suite.name, TEST_VAR_PASSED_CASE_COUNT, TEST_VAR_CASE_COUNT, \
    100.f * (((float)TEST_VAR_PASSED_CASE_COUNT) / ((float)TEST_VAR_CASE_COUNT))); \
  fprintf(stdout, "[%s] >>> Failed test cases: %d/%d (%.1f%%)\n", \
    test_suite.name, TEST_VAR_FAILED_CASE_COUNT, TEST_VAR_CASE_COUNT, \
    100.f * (((float)TEST_VAR_FAILED_CASE_COUNT) / ((float)TEST_VAR_CASE_COUNT))); \
  fprintf(stdout, "[%s] >>> Total failure count: %d\n\n", test_suite.name, test_suite.failed_test_count)
#endif

#define TEST_SUITE_END \
  ON_TEST_SUITE_END; \
  return 0; \
}

#ifndef ON_TEST_CASE_BEGIN
#define ON_TEST_CASE_BEGIN \
fprintf(stdout, "[%s]<%s> Starting test case...\n", test_suite.name, current_case->name)
#endif

#define TEST_CASE_BEGIN(name) \
TEST_VAR_CASE_COUNT++; \
struct test_case_status TEST_NEW_CASE_VARNAME = (struct test_case_status) { name, 0, NULL }; \
if (current_case == NULL) test_suite.first_case = & TEST_NEW_CASE_VARNAME ; \
else current_case->next_case = & TEST_NEW_CASE_VARNAME ; \
current_case = & TEST_NEW_CASE_VARNAME ; \
ON_TEST_CASE_BEGIN;

#ifndef ON_TEST_CASE_END
#define ON_TEST_CASE_END \
fprintf(stdout, "[%s]<%s> Test case finished.\n\n", test_suite.name, current_case->name)
#endif

#define TEST_CASE_END \
test_suite.failed_test_count += current_case->failed_tests; \
TEST_VAR_FAILED_CASE_COUNT += min(1, current_case->failed_tests); \
ON_TEST_CASE_END;

#ifndef ON_TEST_FAILURE_FILE_LINE
#define ON_TEST_FAILURE_FILE_LINE \
  fprintf(stdout, "[%s]<%s> FAIL! %s:%d\n", test_suite.name, current_case->name, __FILE__, __LINE__)
#endif

#ifndef ON_TEST_EXPR_FAILURE
#define ON_TEST_EXPR_FAILURE(expr) \
  fprintf(stdout, "[%s]<%s> Expression " # expr " is falsy!\n\n", test_suite.name, current_case->name)
#endif

#define TEST_EXPR(expr) \
if (!(expr)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_EXPR_FAILURE(expr); \
}

#ifndef ON_TEST_EQ_FAILURE
#define ON_TEST_EQ_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be equal to " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_EQ(a,b) \
if (!((a) == (b))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_EQ_FAILURE(a,b); \
}

#ifndef ON_TEST_NE_FAILURE
#define ON_TEST_NE_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " and " #b " to differ but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_NE(a,b) \
if ((a) == (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_NE_FAILURE(a,b); \
}

#ifndef ON_TEST_LE_FAILURE
#define ON_TEST_LE_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be less or equal than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_LE(a,b) \
if ((a) > (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_LE_FAILURE(a,b); \
}

#ifndef ON_TEST_LT_FAILURE
#define ON_TEST_LT_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be less than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_LT(a,b) \
if ((a) >= (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_LT_FAILURE(a,b); \
}

#ifndef ON_TEST_GE_FAILURE
#define ON_TEST_GE_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be greater or equal than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_GE(a,b) \
if ((a) < (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_GE_FAILURE(a,b); \
}

#ifndef ON_TEST_GT_FAILURE
#define ON_TEST_GT_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be greater than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_GT(a,b) \
if ((a) <= (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_GT_FAILURE(a,b); \
}

#ifndef ON_TEST_STRUCT_EQ_FAILURE
#define ON_TEST_STRUCT_EQ_FAILURE(u,v) \
  fprintf(stdout, "[%s]<%s> Expected structures " #u " and " #v " to be equal but actually not!\n\n", \
    test_suite.name, current_case->name)
#endif

#define TEST_STRUCT_EQ(u,v) \
if (sizeof(u) != sizeof(v) || CMPLE_MEMCMP((void*) &(u), (void*) &(v), sizeof(u))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STRUCT_EQ_FAILURE(u,v); \
}

#ifndef ON_TEST_STRUCT_NE_FAILURE
#define ON_TEST_STRUCT_NE_FAILURE(u,v) \
  fprintf(stdout, "[%s]<%s> Expected structures " #u " and " #v " to differ but actually not!\n\n", \
    test_suite.name, current_case->name)
#endif

#define TEST_STRUCT_NE(u,v) \
if (sizeof(u) == sizeof(v) && !CMPLE_MEMCMP((void*) &(u), (void*) &(v), sizeof(u))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STRUCT_NE_FAILURE(u,v); \
}

#ifndef ON_TEST_STR_EQ_FAILURE
#define ON_TEST_STR_EQ_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected strings to be equal but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_EQ(x,y) \
if (CMPLE_STRLEN(x) != CMPLE_STRLEN(y) || CMPLE_STRCMP((x), (y))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_EQ_FAILURE(x,y); \
}

#ifndef ON_TEST_STR_NE_FAILURE
#define ON_TEST_STR_NE_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected strings to differ but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_NE(x,y) \
if (CMPLE_STRLEN(x) == CMPLE_STRLEN(y) && !CMPLE_STRCMP((x), (y))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_NE_FAILURE(x,y); \
}

#ifndef ON_TEST_STR_LE_FAILURE
#define ON_TEST_STR_LE_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected x <= y but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> y = %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_LE(x,y) \
if (CMPLE_STRCMP((x),(y)) > 0) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_LE_FAILURE(x,y); \
}

#ifndef ON_TEST_STR_LT_FAILURE
#define ON_TEST_STR_LT_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected x < y but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> y = %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_LT(x,y) \
if (CMPLE_STRCMP((x),(y)) >= 0) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_LT_FAILURE(x,y); \
}

#ifndef ON_TEST_STR_GE_FAILURE
#define ON_TEST_STR_GE_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected x >= y but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> y = %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_GE(x,y) \
if (CMPLE_STRCMP((x),(y)) < 0) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_GE_FAILURE(x,y); \
}

#ifndef ON_TEST_STR_GT_FAILURE
#define ON_TEST_STR_GT_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected x > y but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> y = %s\n\n" , test_suite.name, current_case->name, y)
#endif

#define TEST_STR_GT(x,y) \
if (CMPLE_STRCMP((x),(y)) <= 0) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_GT_FAILURE(x,y); \
}

#ifndef ON_TEST_ARRAY_EQ_FAILURE
#define ON_TEST_ARRAY_EQ_FAILURE(x,y,n) \
  fprintf(stdout, "[%s]<%s> Expected arrays " #x " and " #y " of size %llu to be equal but actually not!\n\n", \
    test_suite.name, current_case->name, n)
#endif

#define TEST_ARRAY_EQ(x,y,n) \
if (CMPLE_MEMCMP((x), (y), n)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_ARRAY_EQ_FAILURE(x,y,n); \
}

#ifndef ON_TEST_ARRAY_NE_FAILURE
#define ON_TEST_ARRAY_NE_FAILURE(x,y,n) \
  fprintf(stdout, "[%s]<%s> Expected arrays " #x " and " #y " of size %llu to differ but actually not!\n\n", \
    test_suite.name, current_case->name, n)
#endif

#define TEST_ARRAY_NE(x,y,n) \
if (!CMPLE_MEMCMP((x), (y), n)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_ARRAY_NE_FAILURE(x,y,n); \
}

/*******/
/* EOF */
/*******/

#ifdef __cplusplus
}
#endif

#endif // CMPLE_H
