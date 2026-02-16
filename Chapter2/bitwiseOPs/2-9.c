#include <stdio.h>

/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount. 
*/

int bitcount(unsigned x)
{
    int upBits = 0;
    while (x != 0)
    {
        x &= (x-1);
        upBits++;
    }
    return(upBits);
}



int main(void)
{    
    unsigned x = 6; //00000110 in binary
    x &= (x-1); 
    /*
        This line takes: 
        00000110(x) and compares the bits with 00000101(x-1) in my example
        And the result: 00000100 
    */
    int input;
    printf("Gimme number to see 1 bits in it:");
    fflush(stdout);
    scanf("%d",&input);

    printf("%d\n",bitcount(input));
    

    return(0);
}