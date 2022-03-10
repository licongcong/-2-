#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

#define MAX_STRING_LENGTH       (1000001)

int main() {
    freopen("20220310UVa10340AllInAll.in", "wb", stdout);
    
    srand((unsigned int)time(NULL));

    int case_cnt = 50;
    for (int i = 0; i < case_cnt; i++) {
        string source;
        string target;
        int source_length = rand() % MAX_STRING_LENGTH;
        for (int sl = 0; sl < source_length; sl++) {
            source += (rand() % 26) + ((rand() % 2) ? 'a' : 'A');
        }

        cout << source << " ";
        
        target = source;
        int add_characters_length = rand() % (MAX_STRING_LENGTH-source_length);
        for (int acl = 0; acl < add_characters_length; acl++) {
            int insert_index = rand() % target.size();
            target.insert(insert_index+ target.begin(), (rand() % 26) + ((rand() % 2) ? 'a' : 'A'));
        }

        if (rand() % 2 == 1) {
            int erase_cnt = rand() % add_characters_length;
            for (int ec = 0; ec < erase_cnt; ec++) {
                int erase_index = rand() % target.size();
                target.erase(target.begin() + erase_index);
            }
        }
        cout << target << endl;
    }
    return 0;
}