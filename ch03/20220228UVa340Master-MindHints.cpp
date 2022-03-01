#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-340
*/

#include <stdio.h>

#define MAX_DATA_CNT        (1000)
#define MAX_CODE_SET_CNT    (10)

int kSecretCode[MAX_DATA_CNT];
int kSecreetCodeCnt[MAX_CODE_SET_CNT];
int kGuessCode[MAX_DATA_CNT];
int kGuessCodeCnt[MAX_CODE_SET_CNT];

int main() {
    int n;
    int game_id = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            kSecretCode[i] = 0;
            kGuessCode[i] = 0;
        }
        for (int i = 0; i < MAX_CODE_SET_CNT; i++) {
            kSecreetCodeCnt[i] = 0;
            kGuessCodeCnt[i] = 0;
        }
        
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &kSecretCode[i]);
            kSecreetCodeCnt[kSecretCode[i]]++;
        }

        printf("Game %d:\n", game_id++);

        while (true) {
            for (int i = 0; i < n; i++) {
                kGuessCode[i] = 0;
            }
            for (int i = 0; i < MAX_CODE_SET_CNT; i++) {
                kGuessCodeCnt[i] = 0;
            }

            for (int i = 0; i < n; i++) {
                scanf("%d", &kGuessCode[i]);
                kGuessCodeCnt[kGuessCode[i]]++;
            }
            if (kGuessCodeCnt[0] != 0) {
                break;
            }

            int strong_match_cnt = 0;
            for (int i = 0; i < n; i++) {
                if (kSecretCode[i] == kGuessCode[i]) {
                    strong_match_cnt++;
                }
            }

            int total_match_cnt = 0;
            for (int i = 0; i < MAX_CODE_SET_CNT; i++) {
                if (kGuessCodeCnt[i] < kSecreetCodeCnt[i]) {
                    total_match_cnt += kGuessCodeCnt[i];
                } else {
                    total_match_cnt += kSecreetCodeCnt[i];
                }
            }

            printf("    (%d,%d)\n", strong_match_cnt, total_match_cnt - strong_match_cnt);
        }
    }
    return 0;
}