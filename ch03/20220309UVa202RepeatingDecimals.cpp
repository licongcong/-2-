#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX_LENGTH_OF_DECIMAL_PLACE         (50)

int main() {
    // freopen("20220309UVa202RepeatingDecimals.in", "rb", stdin);
    // freopen("20220309UVa202RepeatingDecimals.out", "wb", stdout);

    int numerator = 0;
    int denumerator = 0;
    while (scanf("%d %d", &numerator, &denumerator) == 2) {
        // integer part
        printf("%d/%d = ", numerator, denumerator);

        if (numerator < denumerator) {
            printf("0");
        }

        while (numerator / denumerator) {
            printf("%d", numerator / denumerator);
            numerator = numerator % denumerator;
        }
        
        printf(".");

        // decimal part
        map<int, int> remainder;
        string decimal_part;
        int index = 0;
        while (remainder.find(numerator) == remainder.end()) {
            remainder[numerator] = index++;

            numerator = numerator * 10;
            decimal_part += to_string(int(numerator / denumerator));
            numerator = numerator % denumerator;
        }

        // output
        int start = remainder[numerator];
        int end = remainder.size();
        for (int i = 0; i < start; i++) {
            printf("%c", decimal_part[i]);
        }
        printf("(");
        for (int i = start; i < end; i++) {
            if (i == MAX_LENGTH_OF_DECIMAL_PLACE) {
                printf("...");
                break;
            }
            printf("%c", decimal_part[i]);
        }
        printf(")");
        printf("\n");

        printf("   %d = number of digits in repeating cycle\n\n", end-start);
    }

    return 0;
}