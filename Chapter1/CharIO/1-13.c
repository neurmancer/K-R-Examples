#include <stdio.h>


int main(void)
{
	//A program that keeps length log of first words

	int lenghtHistory[10] = {};
	int c = 0;
	int words;
	int i = 0;
	while (i < 10 && (words = getchar()) != EOF)
	{
		if (words == ' ')
		{
			lenghtHistory[i] = c;
			c = 0;
			i++;
		}
		else
		{
			c+=1;
		}
	}


	for (i = 0;i< 10; i++)
	{
		printf("%d\n",lenghtHistory[i]);
	}

	return(0);
}
