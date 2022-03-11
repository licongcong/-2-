#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LENGTH          (100)

int main() {
    freopen("20220310UVaKickdown.in", "wb", stdout);

    srand((unsigned int)time(NULL));

    int case_cnt = 50;
    for (int cc = 0; cc < case_cnt; cc++) {
        int master_section_length = (rand() % (MAX_LENGTH - 1)) + 1;
        for (int msl = 0; msl < master_section_length; msl++) {
            printf("%d", (rand() % 2) + 1);
        }
        printf("\n");

        int driven_section_length = (rand() % (MAX_LENGTH - 1)) + 1;
        for (int dsl = 0; dsl < driven_section_length; dsl++) {
            printf("%d", (rand() % 2) + 1);
        }
        printf("\n");
    }
    return 0;
}