#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH          (101)
#define MAX_ALPHABET_CNT            (26)

char kMessage[MAX_MESSAGE_LENGTH];
char kEncryped[MAX_MESSAGE_LENGTH];
char kMap[MAX_ALPHABET_CNT];
int main() {
    freopen("20220318UVa1339AncientCipher.in", "wb", stdout);

    srand((unsigned int)time(NULL));

    int case_cnt = 50;
    for (int cc = 0; cc < case_cnt; cc++) {
        for (int mi = 0; mi < MAX_ALPHABET_CNT; mi++) {
            kMap[mi] = 'A' + mi;
        }

        int message_length = rand() % MAX_MESSAGE_LENGTH + 1;
        for (int mi = 0; mi < message_length; mi++) {
            kMessage[mi] = rand() % MAX_ALPHABET_CNT + 'A';
        }
        kMessage[message_length] = '\0';

        for (int i = 0; i < 10000; i++) {
            int source_index = rand() % MAX_ALPHABET_CNT;
            int target_index = rand() % MAX_ALPHABET_CNT;

            char temp = kMap[source_index];
            kMap[source_index] = kMap[target_index];
            kMap[target_index] = temp;
        }

        for (int mi = 0; mi < message_length; mi++) {
            kEncryped[mi] = kMap[kMessage[mi] - 'A'];
        }
        kEncryped[message_length] = '\0';

        if (rand() & 1) {
            kEncryped[rand() % message_length] = kMap[rand() % MAX_ALPHABET_CNT];
        }

        printf("%s\n%s\n", kMessage, kEncryped);
    }

    return 0;
}