#include <stdio.h>


int main(void)
{
	/*Fahr to Celcius Table from 0 fahr to 300*/


	int fahr,celcius;
	int lowest = 0;
	int upper = 300;
	int step = 20;

	fahr = lowest;

	while(fahr <= upper)
	{
		celcius = 5*(fahr-32)/9;
		printf("Celcius:%3d\tFahrenheit:%3d\n",celcius,fahr);
		fahr+=step;
	}

	return(0);
}
