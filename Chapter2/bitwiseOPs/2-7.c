#include <stdio.h>

//Exercise 2-7 inverting the bits while the other bits remain untouched K&R page 46

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = (~(~0U << n)) << p;   // n ones shifted to position p
    return x ^ mask;
}