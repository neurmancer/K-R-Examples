#include <stdio.h>
#include <float.h>
#include <limits.h>


//This program determines the ranges of char, short, int, and long
//variables, both signed and unsigned, by printing appropriate values from standard headers

int main(void)
{

	printf("---\t\t\tValues of primitive types in C---\n\t\tLowest\t\tHighest\n");
	printf("Char:%10d\t%10d\n",CHAR_MIN,CHAR_MAX);
	printf("Signed Int:\t%d\t%d\n",INT_MIN,INT_MAX);
	printf("Long:%10ld\t%10ld\n",LONG_MIN,LONG_MAX);
	printf("Signed Char:%10d\t%10d\n",SCHAR_MIN,SCHAR_MAX);
	printf("Short int:%10d\t%10d\n",SHRT_MIN,SHRT_MAX);
	printf("Unsigned int:%10u\t%10u\n",0,UINT_MAX);
	printf("Unsigned Long:%10d\t%10lu\n",0,ULONG_MAX);
	printf("Unsigned Short:%10d\t%10u\n",0,USHRT_MAX);


	return(0);
}
