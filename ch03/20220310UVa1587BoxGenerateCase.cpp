#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH          (10000)
#define MAX_LENGTH_CNT      (3)
#define MAX_SUFFACE_CNT     (6)

int main() {
    freopen("20220310UVa1587Box.in", "wb", stdout);

    srand((unsigned int)time(NULL));
    
    int test_case = 50;
    for (int tc = 0; tc < test_case; tc++) {
        int default_length[MAX_LENGTH_CNT] = { 0 };
        for (int lc = 0; lc < MAX_LENGTH_CNT; lc++) {
            default_length[lc] = rand() % MAX_LENGTH + 1;
        }

        for (int sc = 0; sc < MAX_SUFFACE_CNT; sc++) {
            printf("%d %d\n", default_length[rand() % MAX_LENGTH_CNT], default_length[rand() % MAX_LENGTH_CNT]);
        }
    }
    
    return 0;
}