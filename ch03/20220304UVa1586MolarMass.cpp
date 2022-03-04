#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

/*
* https://vjudge.net/problem/UVA-1586
*/

#include <stdio.h>

#define MAX_MOLECULAR_FORMULAT_LENGTH          (81)

/*
* C: 0
* H: 1
* N: 2
* O: 3
*/
int kChr2Integer[26] = { -1, -1, 0, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
double kStandardAtomicWeight[4] = { 12.01, 1.008, 14.01, 16.00 };

int main() {
    int case_cnt = 0;
    scanf("%d", &case_cnt);

    char molecular_formula[MAX_MOLECULAR_FORMULAT_LENGTH] = "\0";
    double molar_mass = 0;
    for (int i = 0; i < case_cnt; i++) {
        double molar_mass = 0;

        scanf("%s", molecular_formula);
        char* char_ptr = molecular_formula;
        while (*char_ptr) {
            int quantity_number = 0;
            int atomic = -1;

            atomic = kChr2Integer[(*char_ptr++) - 'A'];
            if ((*char_ptr >= 'A' && *char_ptr <= 'Z') || (*char_ptr == '\0')) {
                molar_mass += kStandardAtomicWeight[atomic];
            } else {
                while ((*char_ptr >= '0') && (*char_ptr <= '9')) {
                    quantity_number = quantity_number * 10 + (*char_ptr - '0');
                    char_ptr++;
                }
                molar_mass += kStandardAtomicWeight[atomic] * quantity_number;
            }
        }

        printf("%.3lf\n", molar_mass);
    }
    return 0;
}