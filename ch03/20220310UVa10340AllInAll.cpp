/*
* https://vjudge.net/problem/UVA-10340
*/

#include <stdio.h>

#define MAX_STRING_LENGTH       (1000001)

char kSourceString[MAX_STRING_LENGTH];
int main() {

    // freopen("20220310UVa10340AllInAll.in", "rb", stdin);
    // freopen("20220310UVa10340AllInAll.out", "wb", stdout);

    while (scanf("%s", kSourceString) != -1) {
        char character = '\0';
        char* p_source = kSourceString;
        while ((character = getchar()) && character != '\n') {
            if (*p_source == character) {
                p_source++;
            }
        }

        if (*p_source == '\0') {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }


    return 0;
}
