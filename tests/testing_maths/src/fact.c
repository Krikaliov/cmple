#include "fact.h"

int fact_recursive(const int n)
{
if(n<0) return -1;
if(n<1) return 1;
if(n<3) return n;
return n*fact_recursive(n-1);
}

int fact_imperative(const int n)
{
if(n<0) return -1;
if(n<1) return 1;
register int i=n;
register int x=n;
while(--i) x*=i;
return x;
}
