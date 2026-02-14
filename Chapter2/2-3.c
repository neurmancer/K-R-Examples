#include <ctype.h>  // For tolower()

int htoi(const char *s) {
    int value = 0;
    int i = 0;

    // Skip optional "0x" or "0X"
    if (s[0] == '0' && (tolower(s[1]) == 'x')) {
        i = 2;
    }

    // Now convert the hex digits
    while (s[i] != '\0') {
        char c = tolower(s[i]);
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            break;
        }

        value = value * 16 + digit;
        i++;
    }

    return value;
}