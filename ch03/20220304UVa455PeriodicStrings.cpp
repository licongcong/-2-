#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-455
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHARACTOER_CNT          (81)
#define DEBUG
int main() {
#ifdef DEBUG
    FILE* fin, * fout;
    fin = fopen("20220304UVa455PeriodicStrings.in", "rb");
    fout = fopen("20220304UVa455PeriodicStrings.out", "wb");
#endif // DEBUG

    int case_cnt = 0;
#ifdef DEBUG
    fscanf(fin, "%d", &case_cnt);
#else
    scanf("%d", &case_cnt);
#endif // DEBUG


    for (int i = 0; i < case_cnt; i++) {
        char characters[MAX_CHARACTOER_CNT] = "\0";
#ifdef DEBUG
        fscanf(fin, "%s", characters);
#else
        scanf("%s", characters);
#endif // DEBUG

        int start = 0;
        int end = 0;
        int periodic = end - start + 1;
        int string_length = strlen(characters);
        for (int j = 1; j < string_length; j++) {
            if (characters[j] != characters[j % periodic]) {
                end++;
                periodic = end - start + 1;
                j = end;
            }
        }

        if (string_length % periodic != 0) {
            periodic = string_length;
        }
#ifdef DEBUG
        fprintf(fout, "%d\n", periodic);
        if (i != case_cnt - 1) {
            fprintf(fout, "\n");
        }
#else
        printf("%d\n", periodic);
        if (i != case_cnt - 1) {
            printf("\n");
        }
#endif // DEBUG

    }
#ifdef DEBUG
    fclose(fin);
    fclose(fout);
#endif // DEBUG



    return 0;
}