#include <stdio.h>
#include <limits.h> // For INT_MIN because I ain't memorizing the max int limit and shit
#include <string.h> //For strlen
/* reverse: reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


void itoa(int n, char s[])
{
    int i = 0;
    unsigned un;
    
    if (n < 0) {
        s[i++] = '-';
        if (n == INT_MIN)
            un = (unsigned) -(n + 1);   // -(-2147483648 -1) = 2147483647
        else
            un = (unsigned) -n;
    } else {
        un = (unsigned) n;
    }
    
    // Now work with unsigned — no overflow possible anymore
    do {
        s[i++] = (un % 10) + '0';
        un /= 10;
    } while (un > 0);
    
    s[i] = '\0';
    reverse(s);
    
    if (n == INT_MIN)
        s[1]++;   
}

#include <stdio.h>

int main(void)
{
    char buf[32];

    itoa(12345, buf);
    printf("12345 → %s\n", buf);

    itoa(-12345, buf);
    printf("-12345 → %s\n", buf);

    itoa(0, buf);
    printf("0 → %s\n", buf);

    itoa(INT_MIN, buf);               // the fucked up one
    printf("INT_MIN → %s\n", buf);

    itoa(INT_MAX, buf);
    printf("INT_MAX → %s\n", buf);

    return 0;
}