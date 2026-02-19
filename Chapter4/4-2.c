#include <stdio.h>
#include <ctype.h>

/*
Exercise 4-2. Extend atof to handle scientific notation of the form
 123.45e-6

 where a floating-point number may be followed by e or E and an optionally signed exponent

(I am not totally sure with this one but here my explanation goes)
*/


double atof(char s[])
{
    double val = 0.0, power = 1.0;
    int i = 0, sign = 1, exp_sign = 1, exponent = 0;


    while (isspace(s[i]))
        i++;

    // Optional sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Read integer part
    while (isdigit(s[i])) {
        val = 10.0 * val + (s[i] - '0');
        i++;
    }

    // Optional decimal point + fractional part
    if (s[i] == '.') {
        i++;  // skip the '.'
        while (isdigit(s[i])) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
            i++;
        }
    }

    // Optional exponent part: e/E + optional sign + digits
    if (tolower(s[i]) == 'e') {
        i++;  // skip 'e' or 'E'

        // Optional exponent sign
        if (s[i] == '+' || s[i] == '-') {
            exp_sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Read exponent digits
        while (isdigit(s[i])) {
            exponent = 10 * exponent + (s[i] - '0');
            i++;
        }

        // Apply exponent: val * 10^exponent (with sign)
        while (exponent-- > 0)
            val *= (exp_sign == 1) ? 10.0 : 0.1;
    }

    return(sign * val / power);
}