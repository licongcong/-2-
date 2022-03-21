#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_SIZE                   (200)
#define MAX_CHAR_CNT                    (26)

int main() {
    freopen("20220318UVa489HangmanJudge.in", "wb", stdout);

    srand((unsigned int)time(NULL));

    int case_cnt = 50;
    for (int cc = 0; cc < case_cnt; cc++) {
        printf("%d\n", cc + 1);

        for (int si = 0; si < rand() % MAX_WORD_SIZE + 1; si++) {
            printf("%c", rand() % MAX_CHAR_CNT + 'a');
        }
        printf("\n");

        for (int ci = 0; ci < rand() % MAX_WORD_SIZE + 1; ci++) {
            printf("%c", rand() % MAX_CHAR_CNT + 'a');
        }
        printf("\n");

    }

    printf("-1\n");
    return 0;
}