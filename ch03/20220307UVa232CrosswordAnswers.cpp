#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-232
*/

#include <stdio.h>

#define MAX_GRID_SIZE       (11)
#define SHIFT_BIT_CNT       (8)

char kGrid[MAX_GRID_SIZE][MAX_GRID_SIZE];
int kDirectionAndStartId[MAX_GRID_SIZE][MAX_GRID_SIZE];

enum EnumStart {
    ENUM_START_NONE = 0x00,
    ENUM_START_ACROSS = 0x01,
    ENUM_START_DOWN = 0x02
};

int GetDirection(int row, int col) {
    int start = ENUM_START_NONE;

    if (kGrid[row][col] == '*') {
        return start;
    }

    // Across
    if (col - 1 < 0) {
        start |= ENUM_START_ACROSS;
    }
    if (col - 1 >= 0 && kGrid[row][col-1] == '*') {
        start |= ENUM_START_ACROSS;
    }

    // Down
    if (row - 1 < 0) {
        start |= ENUM_START_DOWN;
    }
    if (row - 1 >= 0 && kGrid[row-1][col] == '*') {
        start |= ENUM_START_DOWN;
    }

    return start;
}
int main() {
    freopen("20220309UVa232CrosswordAnswers.in", "rb", stdin);
    freopen("20220309UVa232CrosswordAnswers.out", "wb", stdout);

    int row = -1;
    int col = -1;
    int puzzle_cnt = 1;
    while (true) {

        scanf("%d", &row);

        if (row == 0) {
            return 0;
        }

        if (puzzle_cnt != 1) {
            printf("\n");
        }

        scanf("%d", &col);

        for (int i = 0; i <= row; i++) {
            for (int j = 0; j <= col; j++) {
                kGrid[i][j] = '\0';
            }
        }
        for (int i = 0; i < row; i++) {
            scanf("%s", &kGrid[i][0]);
        }
        
        // Get start id and direction
        int start_id = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int direction = GetDirection(i, j);
                if (direction != 0) {
                    kDirectionAndStartId[i][j] = ((direction << SHIFT_BIT_CNT) | start_id++);
                } else {
                    kDirectionAndStartId[i][j] = 0;
                }
            }
        }

        // Output
        printf("puzzle #%d:\n", puzzle_cnt++);

        // Across
        printf("Across\n");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int direction_and_start_id = kDirectionAndStartId[i][j];
                int direction = (direction_and_start_id >> SHIFT_BIT_CNT);
                int start_id = (0x00FF & direction_and_start_id);
                if ((direction & ENUM_START_ACROSS) != 0) {

                    char words[MAX_GRID_SIZE] = "\0";
                    char* p_words = words;
                    int k = j;
                    while (kGrid[i][k] != '\0' && kGrid[i][k] != '*') {
                        *p_words++ = kGrid[i][k++];
                    }
                    *p_words = '\0';

                    printf("%3d.%s\n", start_id, words);
                }
            }
        }
        // Down
        printf("Down\n");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int direction_and_start_id = kDirectionAndStartId[i][j];
                int direction = (direction_and_start_id >> SHIFT_BIT_CNT);
                int start_id = (0x00FF & direction_and_start_id);
                if ((direction & ENUM_START_DOWN) != 0) {

                    char words[MAX_GRID_SIZE] = "\0";
                    char* p_words = words;
                    int k = i;
                    while (kGrid[k][j] != '\0' && kGrid[k][j] != '*') {
                        *p_words++ = kGrid[k++][j];
                    }
                    *p_words = '\0';

                    printf("%3d.%s\n", start_id, words);
                }
            }
        }
    }

    return 0;
}
