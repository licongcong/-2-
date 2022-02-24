/*
* https://vjudge.net/problem/UVA-10082
*/

#include <stdio.h>

char kKeyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    char chr = '\0';
    char* ptr = 0;

    while ((chr = getchar()) != EOF) {
        ptr = kKeyboard;
        while ((*ptr != chr) && (*ptr != '\0')) {
            ptr++;
        }

        if (*ptr != '\0') {
            printf("%c", *(--ptr));
        } else {
            printf("%c", chr);
        }
    }

    return 0;
}