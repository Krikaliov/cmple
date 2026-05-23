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

#ifndef CMPLE_INLINE
#define CMPLE_INLINE static inline
#endif

#define RAW_PASTE(x,y) x##y
#define PASTE(x,y) RAW_PASTE(x,y)

#define CMPLE_UNKNOWN CMPLE_UNKNOWN
#define CMPLE_UNKNOWN_T void*
#define CMPLE_UNKNOWN_FMT "%p"

#define CMPLE_INT8 CMPLE_INT8
#ifndef CMPLE_INT8_T
#define CMPLE_INT8_T char
#endif
#ifndef CMPLE_INT8_FMT
#define CMPLT_INT8_FMT "%02x"
#endif

#define CMPLE_UINT8 CMPLE_UINT8
#ifndef CMPLE_UINT8_T
#define CMPLE_UINT8_T unsigned CMPLE_INT8_T
#endif
#ifndef CMPLE_UINT8_FMT
#define CMPLE_UINT8_FMT CMPLT_INT8_FMT
#endif

#define CMPLE_INT16 CMPLE_INT16
#ifndef CMPLE_INT16_T
#define CMPLE_INT16_T short
#endif
#ifndef CMPLE_INT16_FMT
#define CMPLE_INT16_FMT "%d"
#endif

#define CMPLE_UINT16 CMPLE_UINT16
#ifndef CMPLE_UINT16_T
#define CMPLE_UINT16_T unsigned CMPLE_INT16_T
#endif
#ifndef CMPLE_UINT16_FMT
#define CMPLE_UINT16_FMT "%u"
#endif

#define CMPLE_INT32 CMPLE_INT32
#ifndef CMPLE_INT32_T
#define CMPLE_INT32_T int
#endif
#ifndef CMPLE_INT32_FMT
#define CMPLE_INT32_FMT "%d"
#endif

#define CMPLE_UINT32 CMPLE_UINT32
#ifndef CMPLE_UINT32_T
#define CMPLE_UINT32_T unsigned CMPLE_INT32_T
#endif
#ifndef CMPLE_UINT32_FMT
#define CMPLE_UINT32_FMT "%u"
#endif

#define CMPLE_INT64 CMPLE_INT64
#ifndef CMPLE_INT64_T
#define CMPLE_INT64_T long
#endif
#ifndef CMPLE_INT64_FMT
#define CMPLE_INT64_FMT "%ld"
#endif

#define CMPLE_UINT64 CMPLE_UINT64
#ifndef CMPLE_UINT64_T
#define CMPLE_UINT64_T unsigned CMPLE_INT64_T
#endif
#ifndef CMPLE_UINT64_FMT
#define CMPLE_UINT64_FMT "%lu"
#endif

#define CMPLE_INT128 CMPLE_INT128
#ifndef CMPLE_INT128_T
#define CMPLE_INT128_T long long
#endif
#ifndef CMPLE_INT128_FMT
#define CMPLT_INT128_FMT "%lld"
#endif

#define CMPLE_UINT128 CMPLE_UINT128
#ifndef CMPLE_UINT128_T
#define CMPLE_UINT128_T unsigned CMPLE_INT128_T
#endif
#ifndef CMPLE_UINT128_FMT
#define CMPLT_UINT128_FMT "%llu"
#endif

#define CMPLE_FLOAT32 CMPLE_FLOAT32
#ifndef CMPLE_FLOAT32_T
#define CMPLE_FLOAT32_T float
#endif
#ifndef CMPLE_FLOAT32_FMT
#define CMPLE_FLOAT32_FMT "%f"
#endif

#define CMPLE_UFLOAT32 CMPLE_UFLOAT32
#ifndef CMPLE_UFLOAT32_T
#define CMPLE_UFLOAT32_T unsigned CMPLE_FLOAT32_T
#endif
#ifndef CMPLE_UFLOAT32_FMT
#define CMPLE_UFLOAT32_FMT CMPLE_FLOAT32_FMT
#endif

#define CMPLE_FLOAT64 CMPLE_FLOAT64
#ifndef CMPLE_FLOAT64_T
#define CMPLE_FLOAT64_T double
#endif
#ifndef CMPLE_FLOAT64_FMT
#define CMPLE_FLOAT64_FMT "%lf"
#endif

#define CMPLE_UFLOAT64 CMPLE_UFLOAT64
#ifndef CMPLE_UFLOAT64_T
#define CMPLE_UFLOAT64_T unsigned CMPLE_FLOAT64_T
#endif
#ifndef CMPLE_UFLOAT64_FMT
#define CMPLE_UFLOAT64_FMT CMPLE_FLOAT64_FMT
#endif

#define CMPLE_FLOAT128 CMPLE_FLOAT128
#ifndef CMPLE_FLOAT128_T
#define CMPLE_FLOAT128_T long double
#endif
#ifndef CMPLE_FLOAT128_FMT
#define CMPLE_FLOAT128_FMT "%llf"
#endif

#define CMPLE_UFLOAT128 CMPLE_UFLOAT128
#ifndef CMPLE_UFLOAT128_T
#define CMPLE_UFLOAT128_T unsigned CMPLE_FLOAT128_T
#endif
#ifndef CMPLE_UFLOAT128_FMT
#define CMPLE_UFLOAT128_FMT CMPLE_FLOAT128_FMT
#endif

#define CMPLE_CHR CMPLE_CHR
#ifndef CMPLE_CHR_T
#define CMPLE_CHR_T CMPLE_INT8_T
#endif
#ifndef CMPLE_CHR_FMT
#define CMPLE_CHR_FMT "%c"
#endif

#define CMPLE_UCHR CMPLE_UCHR
#ifndef CMPLE_UCHR_T
#define CMPLE_UCHR_T unsigned CMPLE_CHR_T
#endif
#ifndef CMPLE_UCHR_FMT
#define CMPLE_UCHR_FMT CMPLE_CHR_FMT
#endif

#ifndef CMPLE_SIZE_T
#define CMPLE_SIZE_T CMPLE_UINT64
#endif

#define CMPLE_T(t) PASTE(t,_T)
#define CMPLE_FMT(t) PASTE(t,_FMT)

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

CMPLE_INLINE int _cmple_memcmp(const void* u, const void* v, const CMPLE_T(CMPLE_SIZE_T) n)
{
  CMPLE_T(CMPLE_SIZE_T) i = 0;
  const unsigned char* pu = (const unsigned char*) u;
  const unsigned char* pv = (const unsigned char*) v;
  while (i < n && (pu[i] == pv[i])) i++;
  return i < n ? (int)(pu[i] - pv[i]) : 0;
}
#ifndef CMPLE_MEMCMP
#define CMPLE_MEMCMP(u,v,n) _cmple_memcmp(u,v,n)
#endif

CMPLE_INLINE CMPLE_T(CMPLE_SIZE_T) _cmple_strlen(const char* x)
{
  const char* start = x;
  while (*x) x++;
  return (CMPLE_T(CMPLE_SIZE_T))(x - start);
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
  struct test_case_status* next_case;
  unsigned int failed_tests;
  unsigned int default_padding;
};

struct test_suite_status
{
  const char name[TEST_NAME_LENGTH];
  struct test_case_status* first_case;
  unsigned int test_case_count;
  unsigned int failed_test_case_count;
  unsigned int failed_test_count;
  unsigned int default_padding;
};

/*************************/
/* TEST PUBLIC CONSTANTS */
/*************************/

/**
 * Name of the test suite
 * @param type string
 * @param scope inside test suite, inside and/or outside any test case
 */
#define TEST_VAR_SUITE_NAME (test_suite.name)

/**
 * Number of test cases in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_CASE_COUNT (test_suite.test_case_count)

/**
 * Number of test cases that passed in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_PASSED_CASE_COUNT (test_suite.test_case_count - test_suite.failed_test_case_count)

/**
 * Number of test cases that failed in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of test cases that have run before the call of this constant.
 */
#define TEST_VAR_FAILED_CASE_COUNT (test_suite.failed_test_case_count)

/**
 * Number of total fails in this test suite
 * @param type unsigned int
 * @param scope inside test suite, inside and/or outside any test case
 * @note This only takes account of tests that have run before the call of this constant.
 */
#define TEST_VAR_TOTAL_FAILURE_COUNT (test_suite.failed_test_count)

/**
 * Name of the current test case
 * @param type string
 * @param scope only inside test case
 */
#define TEST_VAR_CURRENT_CASE_NAME (current_case->name)

/**
 * Number of tests that failed in this test case
 * @param type unsigned int
 * @param scope only inside test case
 * @note This only takes account of tests that have run before the call of this constant inside the test case.
 */
#define TEST_VAR_CURRENT_CASE_FAILS (current_case->failed_tests)

/******************/
/* TEST FUNCTIONS */
/******************/
#ifndef ON_TEST_SUITE_BEGIN
#define ON_TEST_SUITE_BEGIN \
  fprintf(stdout, "[%s] Starting test suite...\n", test_suite.name)
#endif

#define TEST_SUITE_BEGIN(name) \
int main(int argc, char** argv) { \
  if (argc > 1 && CMPLE_STRCMP(argv[1], "--skip")) return 0; \
  struct test_suite_status test_suite = (struct test_suite_status) { name, NULL, 0, 0, 0, 0 }; \
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

#ifndef TEST_SUITE_VALUE_RETURNED
#define TEST_SUITE_VALUE_RETURNED TEST_VAR_TOTAL_FAILURE_COUNT
#endif

#define TEST_SUITE_END \
  ON_TEST_SUITE_END; \
  return TEST_SUITE_VALUE_RETURNED ; \
}

#ifndef ON_TEST_CASE_BEGIN
#define ON_TEST_CASE_BEGIN \
fprintf(stdout, "[%s]<%s> Starting test case...\n", test_suite.name, current_case->name)
#endif

#define TEST_CASE_BEGIN(name) \
TEST_VAR_CASE_COUNT++; \
struct test_case_status TEST_NEW_CASE_VARNAME = (struct test_case_status) { name, NULL, 0, 0 }; \
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
#define ON_TEST_EQ_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be equal to " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_EQ(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if (!( PASTE(test_eq_var_a_,__LINE__) == PASTE(test_eq_var_b_,__LINE__) )) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_EQ_FAILURE(a,b,t); \
}

#ifndef ON_TEST_NE_FAILURE
#define ON_TEST_NE_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " and " #b " to differ but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_NE(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if ( PASTE(test_eq_var_a_,__LINE__) == PASTE(test_eq_var_b_,__LINE__) ) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_NE_FAILURE(a,b,t); \
}

#ifndef ON_TEST_LE_FAILURE
#define ON_TEST_LE_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be less or equal than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_LE(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if ( PASTE(test_eq_var_a_,__LINE__) > PASTE(test_eq_var_b_,__LINE__) ) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_LE_FAILURE(a,b,t); \
}

#ifndef ON_TEST_LT_FAILURE
#define ON_TEST_LT_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be less than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_LT(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if ( PASTE(test_eq_var_a_,__LINE__) >= PASTE(test_eq_var_b_,__LINE__) ) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_LT_FAILURE(a,b,t); \
}

#ifndef ON_TEST_GE_FAILURE
#define ON_TEST_GE_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be greater or equal than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_GE(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if ( PASTE(test_eq_var_a_,__LINE__) < PASTE(test_eq_var_b_,__LINE__) ) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_GE_FAILURE(a,b,t); \
}

#ifndef ON_TEST_GT_FAILURE
#define ON_TEST_GT_FAILURE(a,b,t) \
  fprintf(stdout, "[%s]<%s> Expected " #a " to be greater than " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> " #a " evaluates to " CMPLE_FMT(t) "\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> >>> " #b " evaluates to " CMPLE_FMT(t) "\n\n", test_suite.name, current_case->name, b)
#endif

#define TEST_GT(a,b,t) \
const CMPLE_T(t) PASTE(test_eq_var_a_,__LINE__) = a ; \
const CMPLE_T(t) PASTE(test_eq_var_b_,__LINE__) = b ; \
if ( PASTE(test_eq_var_a_,__LINE__) <= PASTE(test_eq_var_b_,__LINE__) ) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_GT_FAILURE(a,b,t); \
}

#ifndef ON_TEST_STR_EQ_FAILURE
#define ON_TEST_STR_EQ_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> Expected strings to be equal but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> y = %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> y = %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> y = %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> >>> x = %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> >>> y = %s\n\n" , test_suite.name, current_case->name, y)
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
  fprintf(stdout, "[%s]<%s> Expected arrays " #x " and " #y " of size " CMPLE_FMT(CMPLE_SIZE_T) " to be equal but actually not!\n\n", \
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
  fprintf(stdout, "[%s]<%s> Expected arrays " #x " and " #y " of size " CMPLE_FMT(CMPLE_SIZE_T) " to differ but actually not!\n\n", \
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
