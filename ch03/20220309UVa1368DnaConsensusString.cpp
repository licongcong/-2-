#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-1368
*/

#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_DNA_SEQUENCE          (55)
#define MAX_LENGTH_OF_DNA_SEQUENCE          (1005)
#define MAX_CHARACTOER_CNT                  (26)
#define MAX_DNA_CHARACTER_CNT               (4)

int kNumOfDnaSequence = 0;
int kLenOfDnaSequence = 0;

char kDnaTable[MAX_NUMBER_OF_DNA_SEQUENCE][MAX_LENGTH_OF_DNA_SEQUENCE];
int kChar2Int[MAX_CHARACTOER_CNT] = { 0, -1, 1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1 };
char kDnaChrTable[MAX_DNA_CHARACTER_CNT] = { 'A', 'C', 'G', 'T' };

int main() {
    // freopen("20220309UVa1368DnaConsensusString.in", "rb", stdin);
    // freopen("20220309UVa1368DnaConsensusString.out", "wb", stdout);

    int case_cnt = 0;
    scanf("%d", &case_cnt);
    for (int c = 0; c < case_cnt; c++) {
        scanf("%d %d", &kNumOfDnaSequence, &kLenOfDnaSequence);

        for (int i = 0; i < kNumOfDnaSequence; i++) {
            scanf("%s", &kDnaTable[i][0]);
        }

        int sum_hamming_distance = 0;
        for (int len = 0; len < kLenOfDnaSequence; len++) {
            
            int chr_count[MAX_DNA_CHARACTER_CNT] = { 0, 0, 0, 0 };
            for (int num = 0; num < kNumOfDnaSequence; num++) {
                chr_count[kChar2Int[kDnaTable[num][len] - 'A']]++;
            }

            int chr_index = 0;
            for (int i = 1; i < MAX_DNA_CHARACTER_CNT; i++) {
                if (chr_count[i] > chr_count[chr_index]) {
                    chr_index = i;
                }
            }

            for (int i = 0; i < MAX_DNA_CHARACTER_CNT; i++) {
                if (i == chr_index) {
                    printf("%c", kDnaChrTable[chr_index]);
                } else {
                    sum_hamming_distance += chr_count[i];
                }
            }
        }

        printf("\n%d\n", sum_hamming_distance);
    }

    return 0;
}