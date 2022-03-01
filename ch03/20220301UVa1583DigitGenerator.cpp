#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-1583
*/

#include <stdio.h>

#define MAX_DIGIT_CNT       (100001)

int kDigitGeneratorTable[MAX_DIGIT_CNT];

int main() {
    for (int i = 0; i < MAX_DIGIT_CNT; i++) {
        kDigitGeneratorTable[i] = 0;
    }

    int generator = 0;
    int n = 0;
    for (int i = 0; i < MAX_DIGIT_CNT; i++) {
        generator = i;
        n = i;
        while (n) {
            generator += n % 10;
            n = n / 10;
        }

        if (kDigitGeneratorTable[generator] == 0) {
            kDigitGeneratorTable[generator] = i;
        }
    }

    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", kDigitGeneratorTable[n]);
    }

    return 0;
}