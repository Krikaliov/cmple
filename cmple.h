#ifndef CMPLE_H
#define CMPLE_H

#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cstring>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifdef __cpluscplus
extern "C" {
#endif

#define GENERIC_FAILURE_MSG ">>> TEST FAILED!"

#ifdef __FILE__
#ifdef __LINE__
#define SOURCE_FILELINE ">>> Source %s at line %d.",__FILE__,__LINE__
#else
#define SOURCE_FILELINE ">>> Source %s.",__FILE__
#endif
#else
#define SOURCE_FILELINE ">>> Unrecognizable source..."
#endif

#define ASSERT_EQ(a,b) \
  if (!((a) == (b))) \
  { \
    fprintf_s( stderr, "\n" GENERIC_FAILURE_MSG ); \
    fprintf_s( stderr, "\n" SOURCE_FILELINE ); \
    fprintf_s( stderr, "\n\t\t" # a " evaluates to %p ", a ); \
    fprintf_s( stderr, "\n\t\t" # b " evaluates to %p ", b ); \
    fprintf_s( stderr, "\n\t\tExpected to be equal but actually not\n" ); \
    failed_tests++; \
  } \

#define TEST_CASE_BEGIN \
  int main(int argc, char** argv) { \
    unsigned int failed_tests = 0;

#define TEST_CASE_END \
  return failed_tests; \
  }

#ifdef __cpluscplus
}
#endif

#endif // CMPLE_H
