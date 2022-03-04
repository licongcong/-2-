#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-1585
*/

#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH       (81)

int main() {
    int case_cnt = 0;
    scanf("%d", &case_cnt);

    char score_string[MAX_STRING_LENGTH] = "\0";
    int correct_answer_score = 0;
    int score = 0;
    for (int i = 0; i < case_cnt; i++) {
        correct_answer_score = 0;
        score = 0;

        scanf("%s", score_string);
        int score_string_length = strlen(score_string);
        for (int i = 0; i < score_string_length; i++) {
            if (score_string[i] == 'O') {
                correct_answer_score++;
                score += correct_answer_score;
            } else {
                correct_answer_score = 0;
            }
        }

        printf("%d\n", score);
    }

    return 0;
}