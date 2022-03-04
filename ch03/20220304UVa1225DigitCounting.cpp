#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-1225
*/

#include <stdio.h>

#define MAX_DIGIT_CNT          (10)


int main() {
    int case_cnt = 0;
    scanf("%d", &case_cnt);

    for (int i = 0; i < case_cnt; i++) {
        int n = 0;
        scanf("%d", &n);

        int digit_count[MAX_DIGIT_CNT] = { 0 };
        for (int j = 1; j <= n; j++) {
            int curr = j;
            while (curr) {
                digit_count[curr % 10]++;
                curr /= 10;
            }
        }

        for (int j = 0; j < 9; j++) {
            printf("%d ", digit_count[j]);
        }
        printf("%d\n", digit_count[9]);
    }

    return 0;
}