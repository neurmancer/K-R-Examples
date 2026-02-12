#include <stdio.h>


int main(void)
{	
	float celc,fahr;
	int step,lower,upper;

	step = 20;
	lower = 0;
	upper = 400;

	fahr = lower;

	printf("\033[10;5HFAHRENHEIT TO CELCIUS TABLE\n\n");

	while (fahr <= upper)
	{
		celc = 5* (fahr-32)/9;
		printf("Fahrenheit:%3.0f\t\tCelcius:%3.1f\n",fahr,celc);
		fahr+=step;
	}
}
