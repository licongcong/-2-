/*
* https://vjudge.net/problem/UVA-133
*/

#include <stdio.h>

#define MAX_N               (20)

int kN[MAX_N];
int GetNextIndex(int curr, int clockwise, int size) {
    if (curr + clockwise > size) {
        return 1;
    }
    if (curr + clockwise == 0) {
        return size;
    }

    return curr + clockwise;
}

int main() {
    // freopen("20220321Uva133TheDoeQueue.in", "rb", stdin);
    // freopen("20220321Uva133TheDoeQueue.out", "wb", stdout);

    int n, k, m;
    while (scanf("%d %d %d", &n, &k, &m) == 3 && n != 0) {
        for (int ni = 0; ni <= n; ni++) {
            kN[ni] = ni;
        }

        int num_cnt = n;
        int k_start = n;
        int m_start = 1;

        while (num_cnt > 0) {
            // next k
            int k_count = k;
            int k_curr_idx = 0;
            while (k_count > 0) {
                int k_next = GetNextIndex(k_start, 1, n);
                if (kN[k_next] != 0) {
                    k_count--;
                    k_curr_idx = k_next;
                }
                k_start = k_next;
            }

            printf("%3d", kN[k_curr_idx]);
            num_cnt--;

            int m_count = m;
            int m_curr_idx = 0;
            while (m_count > 0) {
                int m_next = GetNextIndex(m_start, -1, n);
                if (kN[m_next] != 0) {
                    m_count--;
                    m_curr_idx = m_next;
                }
                m_start = m_next;
            }

            if (m_curr_idx != k_curr_idx) {
                printf("%3d", kN[m_curr_idx]);
                num_cnt--;
            }

            if (num_cnt != 0) {
                printf(",");
            }

            kN[k_curr_idx] = 0;
            kN[m_curr_idx] = 0;

        }
        printf("\n");
    }
    return 0;
}