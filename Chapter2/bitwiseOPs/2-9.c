#include <stdio.h>

/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.  -C Programming Language 2nd Edition 
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
    unsigned x = 6; //00000110 in binary (asumming little-endian) 
    x &= (x-1); 
    /*
        This line takes: 
        00000110(x) and ANDs the bits with 00000101(x-1) in my example
        And the result: 00000100 which is literally the highschool bool logic lectures if you remember the de'morgan's law 
        but for multi-bit binary notation instead of just one 1 and 0   
    */
    int input;
    printf("Gimme number to see 1 bits in it:");
    fflush(stdout); 
    //stdio is line buffered by default it flushes when sees \n or program ends and return() calls clean up to flush the buffers so
    //it's better to flush before scanf since there is no '\n' at the end but if you don't want to do it you can change it with _IONBF flag in setvbuf() function   
    scanf("%d",&input);

    printf("%d\n",bitcount(input));
    

    return(0);
}
}
