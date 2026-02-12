#include <stdio.h>

int main(void)
{
	
//	printf("%d",EOF); Excersie 1-7 //EOF indicator Ctrl+D in Unix and Ctrl+Z on Windows to terminate the loop 

/*Version 1 with while loop
 	
	long nc = 0;

 
	while(getchar() != EOF)
	{
	
		++nc;
	}	
	printf("%ld\n",nc);

*/

//Version 2 with for loop


	double nc;
	for (nc = 0 ; getchar() != EOF;++nc)
	{
	  	continue;
	}

	printf("%.0f\n",nc);


	return(0);
}
