/*
* https://vjudge.net/problem/UVA-1588
*/

#include <stdio.h>

#define MAX_SECTION_LENGTH          (100)
#define MAX_OPTION_CNT              (2)
#define MAX_EXPANDED_SIZE           (3)

// #define DEBUG

int kExpMasterSection[MAX_SECTION_LENGTH * MAX_EXPANDED_SIZE];
char kMasterSection[MAX_SECTION_LENGTH];
int kIntDrivenSection[MAX_SECTION_LENGTH];
char kDrivenSection[MAX_SECTION_LENGTH];

int kMap[MAX_OPTION_CNT] = { 3, 1 };

int main() {

    // freopen("20220310UVa1588Kickdown.in", "rb", stdin);
    // freopen("20220310UVa1588Kickdown.out", "wb", stdout);

    while (true) {
        if (scanf("%s", kMasterSection) == EOF) {
            return 0;
        }
        scanf("%s", kDrivenSection);
        int driven_section_length = 0;
        for (; kDrivenSection[driven_section_length] != '\0'; driven_section_length++) {
            kIntDrivenSection[driven_section_length] = kDrivenSection[driven_section_length] - '0';
        }

        int master_section_length = 0;
        int expanded_master_section_length = 0;
        for (; expanded_master_section_length < driven_section_length; expanded_master_section_length++) {
            kExpMasterSection[expanded_master_section_length] = kMap[0];
        }
        for (; kMasterSection[master_section_length] != '\0'; master_section_length++) {
            kExpMasterSection[expanded_master_section_length++] = kMap[kMasterSection[master_section_length] - '1'];
        }
        for (int dsl = 0; dsl < driven_section_length; dsl++) {
            kExpMasterSection[expanded_master_section_length++] = kMap[0];
        }
#ifdef DEBUG

        for (int i = 0; i < driven_section_length; i++) {
            printf("  ");
        }
        for (int i = 0; i < master_section_length; i++) {
            printf(" %c", kMasterSection[i]);
        }
        for (int i = 0; i < driven_section_length; i++) {
            printf("  ");
        }
        printf("\n");
        for (int i = 0; i < expanded_master_section_length; i++) {
            printf(" %d", kExpMasterSection[i]);
        }
        printf("\n");
        for (int i = 0; i < driven_section_length; i++) {
            printf(" %c", kDrivenSection[i]);
        }
        printf("\n");

#endif // DEBUG
        int min_length = expanded_master_section_length;
        for (int emsl = 0; emsl < expanded_master_section_length - driven_section_length; emsl++) {
            int dsl = 0;
            for (; dsl < driven_section_length ; dsl++) {
                if ((kExpMasterSection[emsl + dsl] & kIntDrivenSection[dsl]) == 0) {
                    break;
                }
            }

            if (dsl == driven_section_length) {
#ifdef DEBUG
                for (int demsl = 0; demsl < expanded_master_section_length; demsl++) {
                    printf(" %d", kExpMasterSection[demsl]);
                }
                printf("\n");
               
                for (int ddsl = 0; ddsl < emsl; ddsl++) {
                    printf("  ");
                }
                for (int ddsl = 0; ddsl < driven_section_length; ddsl++) {
                    printf(" %d", kIntDrivenSection[ddsl]);
                }
                printf("\n");
#endif // DEBUG
                /*
                *    |<------driven------->|<----master--->|<-------driven------>|
                *    |_____________________|_______________|_____________________|
                * 1.         <------driven------->
                * 2.         <------------driven------------->
                * 3.                          <-driven->
                * 4.                               <------driven------->
                */
                int curr_length = 0;
                if (emsl < driven_section_length) {
                    if (emsl >= master_section_length) {
                        curr_length = driven_section_length;
                    } else {
                        curr_length = driven_section_length + master_section_length - emsl;
                    }
                } else if (emsl >= driven_section_length && emsl <= master_section_length) {
                    curr_length = master_section_length;
                } else {
                    curr_length = emsl;
                }
#ifdef DEBUG
                printf("curr[%d] <=> min[%d]\n", curr_length, min_length);
#endif // DEBUG

                if (curr_length < min_length) {
                    min_length = curr_length;
                } else {
                    break;
                }
            }
        }

        printf("%d\n", min_length);
     }
    return 0;
}