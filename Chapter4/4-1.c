#include <stdio.h>


/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/


int strindex(char *s,char t)
{

    int found = -1;
    for (int i = 0; s[i] != '\0';i++)
    {
        if (s[i] == t)
        {
            found = i;
        }
    }
    
    return(found);
}


int main(void)
{

    printf("%d\n",strindex("Allah var",'a'));


    return(0);
}