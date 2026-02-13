#include <stdio.h>
#define BUF_MAX 100


int main(void)
{
	
	char s[BUF_MAX] = "";
	int c,counter=0;

	while ((c=getchar()) != EOF)
	{
		if (c == '\n')
		{
			break;
		}	


		if (counter >= BUF_MAX-1)
		{
			break;
		}
		s[counter] = c;
	       counter++;	
	}

	s[counter] = c;
	printf("%s",s);

	return(0);
}
