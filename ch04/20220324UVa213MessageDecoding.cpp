/*
* https://vjudge.net/problem/UVA-213
*/

#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

#define SEGMENT_BIT_LENGTH          (3)
#define END_FLAG_BIT_CNT            (3)

string GetKey(int character_id, int exponent) {
    int mask = (int)1 << (exponent - 1);
    string key;

    for (int ei = 0; ei < exponent; ei++) {
        if ((character_id & mask) != 0) {
            key += "1";
        } else {
            key += "0";
        }
        mask = mask >> 1;
    }

    return key;
}
map<string, char> GenerateMap(string header) {
    map<string, char> code_map;
    int character_id = 0;
    int exponent = 1;

    for (int hi = 0; hi < header.size(); hi++) {
        if (character_id == (int(1) << exponent )- 1) {
            character_id = 0;
            exponent++;
        }

        code_map[GetKey(character_id++, exponent)] = header[hi];
    }

    return code_map;
}
string GetEndPattern4Len(int length) {
    string end;

    for (int li = 0; li < length; li++) {
        end += "1";
    }

    return end;
}
int GetSegmentLength(string string_length) {
    int mask = 0b100;
    int length = 0;

    for (int mi = 0; mi < SEGMENT_BIT_LENGTH; mi++) {
        if (string_length[mi] == '1') {
            length = length | mask;
        }
        mask = mask >> 1;
    }

    return length;
}
char GetOneBitMessage() {
    char chr = getchar();

    while (chr == '\n' || chr == '\r') {
        chr = getchar();
    }

    return chr;
}
int main() {
    freopen("20220324UVa213MessageDecoding.in", "rb", stdin);
    freopen("20220324UVa213MessageDecoding.out", "wb", stdout);

    while (true) {
        string header;
        getline(cin, header);
        if (header.empty()) {
            break;
        }
        map<string, char> code_map = GenerateMap(header);

        string message;
        string part_message;
        while (true) {
            // Segment length
            string str_segment_length;
            for (int sli = 0; sli < SEGMENT_BIT_LENGTH; sli++) {
                str_segment_length += GetOneBitMessage();
            }
            int segment_length = GetSegmentLength(str_segment_length);
            string end_pattern = GetEndPattern4Len(segment_length);

            // Segment
            while (segment_length != 0) {
                string segment;
                for (int si = 0; si < segment_length; si++) {
                    segment += GetOneBitMessage();
                }
                if (segment.compare(end_pattern) == 0) {
                    break;
                }

                printf("%c", code_map[segment]);
            }

            if (segment_length == 0) {
                break;
            }
        }
        getline(cin, header); // get '\r', '\n' after message

        printf("\n");
    }
    return 0;
}