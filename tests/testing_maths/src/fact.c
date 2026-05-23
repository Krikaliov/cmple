#include "fact.h"

int fact_recursive(int n)
{
  if (n < 0) return -1;
  if (n < 1) return 1;
  if (n < 3) return n;

  return n * fact_recursive(n-1);
}

int fact_imperative(int n)
{
  if (n < 0) return -1;
  if (n < 2) return 1;

  int i = n;
  int x = n;

  while (--i) x *= i;

  return x;
}
