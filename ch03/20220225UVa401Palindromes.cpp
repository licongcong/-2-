#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


/*
* https://vjudge.net/problem/UVA-401
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHARACTER_CNT               (21)

char kReverseTable[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
/*
*                   |   palindrome  |
*                   |   NO |   YES  |
* -----------------------------------
* mirrored  |   NO  |NO, NO| NO, YES| 
*           |   YES |YES,NO| YES,YES|
*/
const char* kMessage[4] = { " -- is not a palindrome.", \
                            " -- is a regular palindrome.", \
                            " -- is a mirrored string.", \
                            " -- is a mirrored palindrome." };

char GetMirroredCharacter(char chr) {
    if (chr >= 'A' && chr <= 'Z') {
        return kReverseTable[chr - 'A'];
    }
    return kReverseTable[chr - '1' + 26];
}

int main() {
    char strings[MAX_CHARACTER_CNT];
    while (scanf("%s", strings) == 1) {
        int string_length = strlen(strings);
        int check_length = (string_length + 1) >> 1;
        int palindrome = 1;
        int mirrored = 1;

        for (int i = 0; i < check_length; i++) {
            if (strings[i] != strings[string_length - i - 1]) {
                palindrome = 0;
            }
            if (strings[i] != GetMirroredCharacter(strings[string_length - i - 1])) {
                mirrored = 0;
            }
        }

        printf("%s%s\n\n", strings, kMessage[2 * mirrored + palindrome]);
    }
    return 0;
}