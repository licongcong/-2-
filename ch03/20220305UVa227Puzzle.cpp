#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-227
*/

#include <stdio.h>

#define MAX_FRAME_SIZE          (5)
#define MAX_CHARACTER_CNT       (26)
#define MAX_DIRECTION_CNT       (4)
#define MAX_DEMENSION_CNT       (2)

// #define DEBUG

char kConfiguration[MAX_FRAME_SIZE][MAX_FRAME_SIZE];
int kChr2Integer[MAX_CHARACTER_CNT] = { 0, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1 };
int kDelta[MAX_DIRECTION_CNT][MAX_DEMENSION_CNT] = {
    {-1, 0},    // A
    {0, 1},     // R
    {1, 0},     // B
    {0, -1}     // L
};

int main() {
#ifdef DEBUG
    FILE* fin, * fout;
    fin = fopen("20220305UVa227Puzzle.in", "rb");
    fout = fopen("20220305UVa227Puzzle.out", "wb");
#endif // DEBUG

    int puzzle_cnt = 1;
    while (true) {
        int x = -1;
        int y = -1;
        int illegal = 0;

        // input
        int character_count = 0;
        while (character_count < 25) {
            int row = character_count / MAX_FRAME_SIZE;
            int col = character_count % MAX_FRAME_SIZE;
            while (true) {
#ifdef DEBUG
                kConfiguration[row][col] = fgetc(fin);
#else
                kConfiguration[row][col] = getchar();
#endif // DEBUG

                if ((kConfiguration[row][col] >= 'A' && kConfiguration[row][col] <= 'Z') || \
                    (kConfiguration[row][col] == ' ')) {
                    break;
                }
            }

            if (kConfiguration[row][col] == ' ') {
                x = row;
                y = col;
            }

            if (kConfiguration[row][col] == 'Z') {
                return 0;
            }
            character_count++;
        }

#ifdef DEBUG
        if (puzzle_cnt != 1) {
            fprintf(fout, "\n");
        }
#else
        if (puzzle_cnt != 1) {
            printf("\n");
        }
#endif // DEBUG


        // processing moves
        char move = '\0';
        while(true) {
#ifdef DEBUG
            move = fgetc(fin);
#else 
            move = getchar();
#endif // DEBUG

            if (move == '0') {
                break;
            }
            if (move == '\r' || move == '\n') {
                continue;
            }

            if (kChr2Integer[move - 'A'] == -1) {
                illegal = 1;
            }
            if (illegal == 1) {
                continue;
            }

            int next_x = x + kDelta[kChr2Integer[move - 'A']][0];
            int next_y = y + kDelta[kChr2Integer[move - 'A']][1];
            if (next_x < 0 || next_x == MAX_FRAME_SIZE || next_y < 0 || next_y == MAX_FRAME_SIZE) {
                illegal = 1;
                continue;
            }

            kConfiguration[x][y] = kConfiguration[next_x][next_y];
            kConfiguration[next_x][next_y] = ' ';
            x = next_x;
            y = next_y;
        }


        // output
#ifdef DEBUG
        fprintf(fout, "Puzzle #%d:\n", puzzle_cnt++);
#else
        printf("Puzzle #%d:\n", puzzle_cnt++);
#endif // DEBUG

        if (illegal == 1) {
#ifdef DEBUG
            fprintf(fout, "This puzzle has no final configuration.\n");
#else
            printf("This puzzle has no final configuration.\n");
#endif // DEBUG
            continue;
        }

        for (int i = 0; i < MAX_FRAME_SIZE; i++) {
            for (int j = 0; j < MAX_FRAME_SIZE; j++) {
#ifdef DEBUG
                fprintf(fout, "%c", kConfiguration[i][j]);
                if (j < MAX_FRAME_SIZE - 1) {
                    fprintf(fout, " ");
                }
#else 
                printf("%c", kConfiguration[i][j]);
                if (j < MAX_FRAME_SIZE - 1) {
                    printf(" ");
                }
#endif // DEBUG
            }
#ifdef DEBUG
            fprintf(fout, "\n");
#else
            printf("\n");
#endif // DEBUG

        }
    }

    return 0;
}
