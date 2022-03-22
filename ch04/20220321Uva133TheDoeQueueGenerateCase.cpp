#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N           (19)
#define MAX_CASE_CNT    (300)
#define MAX_STEP        (10000)
int main() {
    freopen("20220321Uva133TheDoeQueue.in", "wb", stdout);

    srand((unsigned int)time(NULL));

    int case_cnt = rand() % MAX_CASE_CNT;

    for (int cc = 0; cc < case_cnt; cc++) {
        int n = (rand() % MAX_N) + 1;
        int k = (rand() % MAX_STEP) + 1;
        int m = (rand() % MAX_STEP) + 1;
        printf("%d %d %d\n", n, k, m);
    }

    printf("0 0 0");
    return 0;
}