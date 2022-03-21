/*
* https://vjudge.net/problem/UVA-489
*/

#include <stdio.h>

#define MAX_WORD_SIZE           (200)
#define MAX_CHAR_CNT            (26)

char kSolution[MAX_WORD_SIZE];
char kGuesses[MAX_WORD_SIZE];

int main() {
    // freopen("20220318UVa489HangmanJudge.in", "rb", stdin);
    // freopen("20220318UVa489HangmanJudge.out", "wb", stdout);

    int round = 0;
    while (scanf("%d", &round) == 1 && round != -1) {
        int solution_bit_map = 0;
        scanf("%s %s", kSolution, kGuesses);

        char* ptr = kSolution;
        while (*ptr) {
            solution_bit_map |= ((int(1)) << (*ptr - 'a'));
            ptr++;
        }

        int guess_cnt = 0;
        int guess_bit_map = 0;
        ptr = kGuesses;
        while (*ptr) {
            if ((solution_bit_map & (int(1) << (*ptr - 'a'))) == 0) {
                if ((guess_bit_map & (int(1) << (*ptr - 'a'))) == 0){
                    guess_cnt++;
                }

            } else {
                int mask = 0;
                for (int mi = MAX_CHAR_CNT-1; mi >= 0; mi--) {
                    if (mi == (*ptr - 'a')) {
                        mask = mask << 1;
                    } else {
                        mask = (mask << 1) | int(1);
                    }
                }
                solution_bit_map = solution_bit_map & mask;
                if (solution_bit_map == 0) {
                    break;
                }
            }
            guess_bit_map = guess_bit_map | (int(1) << (*ptr - 'a'));

            ptr++;
        }

        printf("Round %d\n", round);
        if (guess_cnt < 7 && solution_bit_map == 0) {
            printf("You win.\n");
        } else if (guess_cnt < 7 && solution_bit_map != 0) {
            printf("You chickened out.\n");
        } else {
            printf("You lose.\n");
        }
    }
    return 0;
}