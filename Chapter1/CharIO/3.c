#include <stdio.h>


int main(void)
{

	int c; 

	while((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			putchar('\b');
		}
		
		else
		{
			putchar(c);
		}
		
	}


	return(0);
}
