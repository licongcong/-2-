/*
 * https://vjudge.net/problem/UVA-272
*/


#include <stdio.h>

int main() {
    char chr = '\0';
    int left_quote_flag = 0;

    while ((chr = getchar()) != EOF) {
        if (chr == '"') {
            if (left_quote_flag == 0) {
                printf("``");
                left_quote_flag = 1;
            } else {
                printf("''");
                left_quote_flag = 0;
            }
        } else {
            printf("%c", chr);
        }
    }

    return 0;
}