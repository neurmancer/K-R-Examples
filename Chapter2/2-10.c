/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else. 
*/


void lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
    }
}
