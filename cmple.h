#ifndef CMPLE_H
#define CMPLE_H

/**
 * TODO:
 * - LE/LT/GE/GT tests for numerals, arrays and strings
 * - Web site for the documentation
 * - CI/CD process via Github Actions
 * - Complete README.md
 * THEN:
 * --> Launch first release
 */

#ifdef __cpluscplus
extern "C" {
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

#define RAW_PASTE(x,y) x##y
#define PASTE(x,y) RAW_PASTE(x,y)

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

#ifndef CMPLE_SIZE_T
#define CMPLE_SIZE_T unsigned long
#endif

#ifndef CMPLE_INLINE
#define CMPLE_INLINE
#endif

CMPLE_INLINE int _cmple_memcmp(const void* u, const void* v, CMPLE_SIZE_T n)
{
  CMPLE_SIZE_T i = 0;
  const unsigned char* pu = (const unsigned char*) u;
  const unsigned char* pv = (const unsigned char*) v;
  while (n - i && (pu[i] == pv[i])) i++;
  return n - i ? (int)(pu[i] - pv[i]) : 0;
}
#define CMPLE_MEMCMP(u,v,n) _cmple_memcmp(u,v,n)

CMPLE_INLINE CMPLE_SIZE_T _cmple_strlen(const char* x)
{
  const char* start = x;
  while (*x) x++;
  return (CMPLE_SIZE_T)(x - start);
}
#define CMPLE_STRLEN(x) _cmple_strlen(x)

CMPLE_INLINE int _cmple_strcmp(const char* x, const char* y)
{
  while (*x && (*x == *y)) { x++; y++; };
  return (int)(*(unsigned char*)x - *(unsigned char*)y);
}
#define CMPLE_STRCMP(x,y) _cmple_strcmp(x,y)

#define TEST_NAME_LENGTH 256

#define NEW_TEST_CASE_NAME PASTE(test_case, __LINE__)

#define TEST_VAR_PASSED_CASES test_suite.test_case_count - test_suite.failed_test_case_count
#define TEST_VAR_SUITE_NAME test_suite.name
#define TEST_VAR_CURRENT_CASE_NAME current_case->name
#define TEST_VAR_CURRENT_CASE_FAILS current_case->failed_tests
#define TEST_VAR_CASE_COUNT test_suite.test_case_count
#define TEST_VAR_FAILED_CASE_COUNT test_suite.failed_test_case_count
#define TEST_VAR_TOTAL_FAILURE_COUNT test_suite.failed_test_count

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

#define ON_TEST_SUITE_BEGIN \
  fprintf(stdout, "[%s] Starting test suite...\n", test_suite.name)

#define TEST_SUITE_BEGIN(name) \
int main(int argc, char** argv) { \
  struct test_suite_status test_suite = (struct test_suite_status) { name, NULL, 0, 0, 0 }; \
  struct test_case_status* current_case = NULL; \
  ON_TEST_SUITE_BEGIN;

#define ON_TEST_SUITE_END \
  fprintf(stdout, "[%s] Test suite finished.\n", test_suite.name); \
  fprintf(stdout, "[%s] >>> Passed test cases: %d/%d (%.1f%%)\n", \
    test_suite.name, TEST_VAR_PASSED_CASES, TEST_VAR_CASE_COUNT, \
    100.f * (((float)TEST_VAR_PASSED_CASES) / ((float)TEST_VAR_CASE_COUNT))); \
  fprintf(stdout, "[%s] >>> Failed test cases: %d/%d (%.1f%%)\n", \
    test_suite.name, TEST_VAR_FAILED_CASE_COUNT, TEST_VAR_CASE_COUNT, \
    100.f * (((float)TEST_VAR_FAILED_CASE_COUNT) / ((float)TEST_VAR_CASE_COUNT))); \
  fprintf(stdout, "[%s] >>> Total failure count: %d\n\n", test_suite.name, test_suite.failed_test_count)

#define TEST_SUITE_END \
  ON_TEST_SUITE_END; \
  return 0; \
}

#define ON_TEST_CASE_BEGIN \
fprintf(stdout, "[%s]<%s> Starting test case...\n", test_suite.name, current_case->name)

#define TEST_CASE_BEGIN(name) \
TEST_VAR_CASE_COUNT++; \
struct test_case_status NEW_TEST_CASE_NAME = (struct test_case_status) { name, 0, NULL }; \
if (current_case == NULL) test_suite.first_case = & NEW_TEST_CASE_NAME ; \
else current_case->next_case = & NEW_TEST_CASE_NAME ; \
current_case = & NEW_TEST_CASE_NAME ; \
ON_TEST_CASE_BEGIN;

#define ON_TEST_CASE_END \
fprintf(stdout, "[%s]<%s> Test case finished.\n\n", test_suite.name, current_case->name)

#define TEST_CASE_END \
test_suite.failed_test_count += current_case->failed_tests; \
TEST_VAR_FAILED_CASE_COUNT += min(1, current_case->failed_tests); \
ON_TEST_CASE_END;

#define ON_TEST_FAILURE_FILE_LINE \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) %s:%d\n", test_suite.name, current_case->name, __FILE__, __LINE__)

#define ON_TEST_EXPR_FAILURE(expr) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expression " # expr " is falsy!\n\n", test_suite.name, current_case->name)

#define TEST_EXPR(expr) \
if (!(expr)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_EXPR_FAILURE(expr); \
}

#define ON_TEST_EQ_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected " #a " to be equal to " #b " but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)

#define TEST_EQ(a,b) \
if (!((a) == (b))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_EQ_FAILURE(a,b); \
}

#define ON_TEST_NE_FAILURE(a,b) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected " #a " and " #b " to differ but actually not!\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) >>> " #a " evaluates to %d\n", test_suite.name, current_case->name, a); \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) >>> " #b " evaluates to %d\n\n", test_suite.name, current_case->name, b)

#define TEST_NE(a,b) \
if ((a) == (b)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_NE_FAILURE(a,b); \
}

#define ON_TEST_STRUCT_EQ_FAILURE(u,v) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected structures " #u " and " #v " to be equal but actually not!\n\n", \
    test_suite.name, current_case->name)

#define TEST_STRUCT_EQ(u,v) \
if (sizeof(u) != sizeof(v) || CMPLE_MEMCMP((void*) &(u), (void*) &(v), sizeof(u))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STRUCT_EQ_FAILURE(u,v); \
}

#define ON_TEST_STRUCT_NE_FAILURE(u,v) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected structures " #u " and " #v " to differ but actually not!\n\n", \
    test_suite.name, current_case->name)

#define TEST_STRUCT_NE(u,v) \
if (sizeof(u) == sizeof(v) && !CMPLE_MEMCMP((void*) &(u), (void*) &(v), sizeof(u))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STRUCT_NE_FAILURE(u,v); \
}

#define ON_TEST_STR_EQ_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected strings to be equal but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n\n" , test_suite.name, current_case->name, y)

#define TEST_STR_EQ(x,y) \
if (CMPLE_STRLEN(x) != CMPLE_STRLEN(y) || CMPLE_STRCMP((x), (y))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_EQ_FAILURE(x,y); \
}

#define ON_TEST_STR_NE_FAILURE(x,y) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected strings to differ but actually not:\n", test_suite.name, current_case->name); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n" , test_suite.name, current_case->name, x); \
  fprintf(stdout, "[%s]<%s> (TEST_FAILED!) >>> %s\n\n" , test_suite.name, current_case->name, y)

#define TEST_STR_NE(x,y) \
if (CMPLE_STRLEN(x) == CMPLE_STRLEN(y) && !CMPLE_STRCMP((x), (y))) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_STR_NE_FAILURE(x,y); \
}

#define ON_TEST_ARRAY_EQ_FAILURE(x,y,n) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected arrays " #x " and " #y " of size %llu to be equal but actually not!\n\n", \
    test_suite.name, current_case->name, n)

#define TEST_ARRAY_EQ(x,y,n) \
if (CMPLE_MEMCMP((x), (y), n)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_ARRAY_EQ_FAILURE(x,y,n); \
}

#define ON_TEST_ARRAY_NE_FAILURE(x,y,n) \
  fprintf(stdout, "[%s]<%s> (TEST FAILED!) Expected arrays " #x " and " #y " of size %llu to differ but actually not!\n\n", \
    test_suite.name, current_case->name, n)

#define TEST_ARRAY_NE(x,y,n) \
if (!CMPLE_MEMCMP((x), (y), n)) \
{ \
  current_case->failed_tests++; \
  ON_TEST_FAILURE_FILE_LINE; \
  ON_TEST_ARRAY_NE_FAILURE(x,y,n); \
}

#ifdef __cpluscplus
}
#endif

#endif // CMPLE_H
