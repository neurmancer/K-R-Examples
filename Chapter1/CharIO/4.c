#include <stdio.h>

//Program that gonna show escape characters \n,\t,\\ instead of applyign

int main(void)
{

	int c;

	while ((c = getchar()) != EOF)
	{
		if (c =='\n') {putchar('\\'); putchar('n');}

		else if(c == '\t') {putchar('\\'); putchar('t');}

		else {putchar(c);}
	}


	return(0);
}
