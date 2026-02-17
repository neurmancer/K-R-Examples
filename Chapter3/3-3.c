#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for tolower, isalpha, isdigit

void expand(const char *s1, char *s2) {
    int i = 0;          // index in s1
    int j = 0;          // index in s2 
    
    while (s1[i] != '\0') {
        // Case 1: literal '-' at start or end → keep it
        if (s1[i] == '-' && (i == 0 || s1[i+1] == '\0')) {
            s2[j++] = '-';
            i++;
            continue;
        }
        
        // Case 2: we see something like 'a-z' or '0-9' or 'A-G'
        if (s1[i+1] == '-' && s1[i+2] != '\0') {
            char start = s1[i];
            char end   = s1[i+2];
            
            // Only expand if start <= end and both same type (letter or digit)
            if ((isalpha(start) && isalpha(end)) || (isdigit(start) && isdigit(end))) {
                if (start <= end) {
                    // Normal range: a → z
                    for (char c = start; c <= end; c++) {
                        s2[j++] = c;
                    }
                } else {
                    // Reverse range: z → a (just copy literally, K&R doesn't say to reverse)
                    s2[j++] = start;
                    s2[j++] = '-';
                    s2[j++] = end;
                }
            } else {
                // Different types or invalid → copy literally
                s2[j++] = start;
                s2[j++] = '-';
                s2[j++] = end;
            }
            
            i += 3;  // skip the whole x-y pattern
            continue;
        }
        
        // Case 3: just a normal character (or malformed stuff)
        s2[j++] = s1[i++];
    }
    
    s2[j] = '\0';  // null-terminate the result
}

int main(void) {
    char s2[256];
    
    const char *tests[] = {
        "a-z",          // abcdefghijklmnopqrstuvwxyz
        "0-9",          // 0123456789
        "a-b-c",        // abc (a-b then literal -c)
        "-a-z",         // -abcdefghijklmnopqrstuvwxyz
        "z-a",          // z-a (invalid range, keep literal)
        "a-z0-9",       // abcdefghijklmnopqrstuvwxyz0123456789
        "A-G-",         // ABCDEFG-
        "-X-Z-",        // -XYZ-
        "hello-world",  // hello-world (no - between letters → literal)
        NULL
    };
    
    for (int i = 0; tests[i] != NULL; i++) {
        expand(tests[i], s2);
        printf("Input:  \"%s\"\nOutput: \"%s\"\n\n", tests[i], s2);
    }
    
    return 0;
}