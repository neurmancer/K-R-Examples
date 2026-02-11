#include <stdio.h>


int main(void)
{
	/*Fahr to Celcius Table from 0 fahr to 300*/


	float fahr,celcius;
	int lowest = 0;
	int upper = 300;
	int step = 20;

	fahr = lowest;

	while(fahr <= upper)
	{
		celcius = 5*(fahr-32.0)/9.0;
		printf("Celcius:%3.1f\tFahrenheit:%3.0f\n",celcius,fahr);
		fahr+=step;
	}

	return(0);
}
