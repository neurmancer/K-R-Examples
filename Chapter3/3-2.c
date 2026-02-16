#include <stdio.h>

/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.
*/

void escape(char *s, const char *t)
{
    int j = 0;
    
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
                
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
                
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\\':           
                s[j++] = '\\';
                s[j++] = '\\';
                break;
                
            default:
                s[j++] = t[i];
                break;
        }
    }
  
    s[j] = '\0';
}


void unescape(char *s, const char *t)
{
    int j = 0;
    int i = 0;
    
    while (t[i] != '\0')
    {
        if (t[i] == '\\')
        {
            i++;                    // skip the backslash
            switch (t[i])
            {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
        
        i++;
    }
    
    s[j] = '\0';
}