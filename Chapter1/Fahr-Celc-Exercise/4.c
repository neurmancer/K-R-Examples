#include <stdio.h>

//Celc to Fahr Converter
int main(void)
{

	float celc,fahr;
	int step,lower,upper;

	step = 4;
	lower = -20;
	upper = 100;
	
	celc = lower;

	while(celc <= upper)
	{
		fahr = (9.0/5.0*celc)+32.0;
		printf("Celcius:%3.0f\tFahrenheit:%3.1f\n",celc,fahr);
		celc+=step;
	}

	return(0);
}
