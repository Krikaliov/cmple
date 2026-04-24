#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#include <stdio.h>
#include <string.h>

#define CMPLE_SIZE_T size_t

#include "cmple.h"

#undef ON_TEST_CASE_BEGIN
#define ON_TEST_CASE_BEGIN \
fprintf(stdout, "[%s]<%s> Starting test case with currently %d failed cases before\n", \
  TEST_VAR_SUITE_NAME, TEST_VAR_CURRENT_CASE_NAME, TEST_VAR_FAILED_CASE_COUNT)

#endif // TEST_CONFIG_H
