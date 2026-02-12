#include <stdio.h>

//Same Fahr Celc Program 300-0 instead of 0-300

int main()
{

	float celc,fahr;
	int step = 20,upper = 300,lower = 0;
	fahr = upper;

	while(fahr >= lower)
	{
		celc = 5.0*(fahr-32.0)/9.0;
		printf("Fahrenheit:%3.0f\tCelcius:%3.1f\n",fahr,celc);
		fahr -=step;
	}
	return(0);
}
