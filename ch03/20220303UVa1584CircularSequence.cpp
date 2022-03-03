#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


/*
* https://vjudge.net/problem/UVA-1584
*/

#include <stdio.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH         (101)

char kSequence[MAX_SEQUENCE_LENGTH];

int StrCompare(int first, int second, int sequence_length) {
    for (int i = 0; i < sequence_length; i++) {
        if (kSequence[(first + i) % sequence_length] == kSequence[(second + i) % sequence_length]) {
            continue;
        }
        if (kSequence[(first + i) % sequence_length] < kSequence[(second + i) % sequence_length]) {
            return 1;
        } else {
            return -1;
        }
    }

    return 0;
}
int main() {
    int case_cnt = 0;
    scanf("%d", &case_cnt);

    for (int i = 0; i < case_cnt; i++) {
        scanf("%s", kSequence);

        int min_index = 0;
        int sequence_length = strlen(kSequence);

        for (int curr = 1; curr < sequence_length; curr++) {
            if (StrCompare(curr, min_index, sequence_length) == 1) {
                min_index = curr;
            }
        }

        for (int curr = 0; curr < sequence_length; curr++) {
            printf("%c", kSequence[(min_index + curr) % sequence_length]);
        }
        printf("\n");
    }

    return 0;
}