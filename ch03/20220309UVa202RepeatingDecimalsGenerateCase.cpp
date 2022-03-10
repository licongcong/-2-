#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    freopen("20220309UVa202RepeatingDecimals.in", "wb", stdout);

    srand((unsigned int)time(NULL));

    int case_cnt = 50;
    for (int i = 0; i < case_cnt; i++) {
        int numerator = rand() % 3000;
        int denumerator = rand() % 2999 + 1;

        printf("%d %d\n", numerator, denumerator);
    }

    return 0;
}