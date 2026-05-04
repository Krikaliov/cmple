#include <stdio.h>
#include <string.h>

#include "date.h"

int format_date(char* str_dest, int years, int months, int days, int hours, int minutes, int seconds, int ms)
{
  if (str_dest == NULL) return 0;
  sprintf(str_dest, "%04d-%02d-%02dT%02d:%02d:%02d.%03dZ", years, months, days, hours, minutes, seconds, ms);
  return 1;
}
