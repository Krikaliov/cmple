#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

#include <stdio.h>
#include <string.h>

#define CMPLE_SIZE_T size_t

#define TEST_SUITE_VALUE_RETURNED 0

#define ON_TEST_CASE_BEGIN \
fprintf(stdout, "[%s]<%s> Starting test case with currently %d failed cases before\n", \
  TEST_VAR_SUITE_NAME, TEST_VAR_CURRENT_CASE_NAME, TEST_VAR_FAILED_CASE_COUNT)

#include "cmple.h"

#endif // TEST_CONFIG_H
