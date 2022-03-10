/*
* https://vjudge.net/problem/UVA-1587
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LENGTH_AND_HEIGHT           (10000)

int main() {

    // freopen("20220310UVa1587Box.in", "rb", stdin);
    // freopen("20220310UVa1587Box.out", "wb", stdout);

    int weight = 0;
    int height = 0;
    while (true) {
        vector<int> length;
        int sum_area = 0;
        for (int line = 0; line < 6; line++) {
            if ((scanf("%d %d", &weight, &height)) == EOF) {
                return 0;
            }

            sum_area += weight * height;
            length.push_back(weight);
            length.push_back(height);
        }
        
        sort(length.begin(), length.end());

        for (int idx = 1; idx <= 3; idx++) {
            length.erase(length.begin() + idx, length.begin() + idx + 3);
        }

        int expect_sum_area = 0;
        for (int wi = 0; wi < length.size(); wi++) {
            for (int hi = wi+1; hi < length.size(); hi++) {
                expect_sum_area += length[wi] * length[hi] * 2;
            }
        }

        printf("%s\n", sum_area == expect_sum_area ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}