#include <stdio.h>


int main(void)
{

	//Excerise 1-8 counting spaces, tabs and newlines
	
	int spaceC = 0, tabC = 0,nlC = 0; //C for counter and nl is newline 
	long c;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ') {spaceC++;}
		else if(c == '\t') {tabC++;}
		
		else if(c == '\n') {nlC++;}

		else {continue;}
	}

	printf("Space Count:%d\nTab Count:%d\nNew Line Count:%d\n",spaceC,tabC,nlC);

	return(0);
}
