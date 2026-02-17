#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // for abs() don't forget later.

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(long n, char s[], int b) {
    if (b < 2 || b > 36) {
        s[0] = '\0';
        return;
    }

    int i = 0;
    int sign = (n < 0) ? -1 : 1;
    long num = labs(n);         // absolute value

    do {
        int digit = num % b;
        s[i++] = (digit <= 9) ? (digit + '0') : (digit - 10 + 'A');
        num /= b;
    } while (num > 0);

    if (sign < 0) s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}
