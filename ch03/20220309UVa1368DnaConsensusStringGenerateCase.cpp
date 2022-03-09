#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char kCharacters[4] = {'A', 'T', 'G', 'C'};

int main() {
    freopen("20220309UVa1368DnaConsensusString.in", "wb", stdout);

    srand((unsigned int)time(NULL));
    
    int case_cnt = 50;
    printf("%d\n", case_cnt);

    for (int i = 0; i < 50; i++) {
        int m = rand() % 47 + 4;
        int n = rand() % 997 + 4;
        printf("%d %d\n", m, n);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                printf("%c", kCharacters[rand() % 4]);
            }
            printf("\n");
        }
    }
    return 0;
}