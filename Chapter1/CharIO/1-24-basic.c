#include <stdio.h>
#include <stdlib.h>



//Not exactly what exercise wants but that's all I can do for know will get update someday eventually

int main(void)
{
	int c,paren = 0,brace = 0,bracket = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '{') {brace++;}
		if (c == '}') {brace--;}
		if (c == '(') {paren++;}
		if (c == ')') {paren--;}
		if (c == '[') {bracket++;}
		if (c == ']') {bracket--;}
	}


	if(paren != 0 || brace != 0 || bracket != 0)
	{
		printf("Unmatched thing found\n");
	}

	return(0);
}
