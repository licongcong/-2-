#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("20220309UVa232CrosswordAnswers.in", "wb", stdout);

    int case_cnt = 50;
    for (int i = 0; i < case_cnt; i++) {
        int row = (rand() % 10) + 1;
        int col = (rand() % 10) + 1;

        printf("%d %d\n", row, col);
        int black_square_cnt = rand() % (row * col);
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (((rand() & 1) == 1) && (black_square_cnt != 0)) {
                    printf("*");
                } else {
                    printf("%c", rand() % 26 + 'A');
                }
            }
            printf("\n");
        }
    }
    printf("0\n");
    
    return 0;
}
