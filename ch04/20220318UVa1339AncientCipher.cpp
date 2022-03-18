/*
* https://vjudge.net/problem/UVA-1339
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH          (101)
#define MAX_ALPHABET_CNT            (26)

int kMessageCnt[MAX_ALPHABET_CNT];
int kEncryptedCnt[MAX_ALPHABET_CNT];
char kMessage[MAX_MESSAGE_LENGTH];

int compare(const void* src, const void* dst) {
    return (*(int*)src) - *((int*)dst);
}

int main() {

    // freopen("20220318UVa1339AncientCipher.in", "rb", stdin);
    // freopen("20220318UVa1339AncientCipher.out", "wb", stdout);

    while (scanf("%s", kMessage) == 1) {
        for (int ai = 0; ai < MAX_ALPHABET_CNT; ai++) {
            kMessageCnt[ai] = 0;
            kEncryptedCnt[ai] = 0;
        }

        char* p_message = kMessage;
        while (*p_message) {
            kMessageCnt[*p_message - 'A']++;
            p_message++;
        }

        scanf("%s", kMessage);
        p_message = kMessage;
        while (*p_message) {
            kEncryptedCnt[*p_message - 'A']++;
            p_message++;
        }

        qsort(kMessageCnt, MAX_ALPHABET_CNT, sizeof(int), compare);
        qsort(kEncryptedCnt, MAX_ALPHABET_CNT, sizeof(int), compare);

        int rst = 0;
        for (int ai = 0; ai < MAX_ALPHABET_CNT; ai++) {
            if (kMessageCnt[ai] != kEncryptedCnt[ai]) {
                rst = 1;
                break;
            }
        }

        printf("%s\n", rst == 0 ? "YES" : "NO");
    }

    return 0;
}