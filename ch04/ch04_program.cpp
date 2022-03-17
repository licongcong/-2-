#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

namespace program_4_1_combinations {
    /*
    * 计算组合数。编写函数，参数是两个非负整数 n 和 m，返回组合数 C_n^m = n!/m!(n-m)!。
    * 其中 m <= n <= 25。例如 n = 25, m = 12 时答案为5200300。
    */
    void GenerateCase() {
        FILE* fout;
        fout = fopen("program_4_1.in", "wb");

        int max_n = 25;
        for (int n = 0; n <= max_n; n++) {
            for (int m = 0; m <= n; m++) {
                fprintf(fout, "%d %d\n", n, m);
            }
        }

        fclose(fout);
    }

    long long factorial(int num) {
        long long rst = 1;
        
        for (int i = 1; i <= num; i++) {
            rst *= i;
        }

        return rst;
    }

    /*
    * C_n^m = n!/m!(n-m)! 
    * （数据溢出）
    */
    long long Combinations(int n, int m) {
        return factorial(n) / (factorial(m) * factorial(n - m));
    }

    /*
    * C_n^m = n!/m!(n-m)!
    * ==> C_n^m = m!(m+1)(m+2)...n/m!(n-m)!
    * ==> C_n^m = (m+1)(m+2)...(n)/(n-m)!
    * 
    * ==> C_n^m = C_n^(n-m)
    */
    long long FactorialFromX2Y(int x, int y) {
        long long rst = 1;

        for (int i = x; i <= y; i++) {
            rst *= i;
        }

        return rst;
    }
    long long CombinationsFractionReduction(int n, int m) {
        if (m < (n >> 1)) { // 增加约掉的因子数，防止越界
            m = n - m;
        }
        
        return FactorialFromX2Y(m + 1, n) / FactorialFromX2Y(1, n - m);
    }

    /*
    * 整个过程一直进行约分
    * 还可以进行 gcd() 进行部分约分，可以减少内层循环次数
    */
    #define MAX_NUM_CNT             (26)
    long long CombinationsFractionReductionAll(int n, int m) {

        int n_array[MAX_NUM_CNT] = { 0 };
        int m_array[MAX_NUM_CNT] = { 0 };
        
        for (int ni = 1; ni <= n; ni++) {
            n_array[ni] = ni;
        }

        // 约掉 m!
        for (int mi = 1; mi <= m; mi++) {
            n_array[mi] = 1;
        }

        // 约掉 (n-m)!
        for (int mi = 1; mi <= n - m; mi++) {
            m_array[mi] = mi;
        }
        long long rst = 1;
        for (int ni = m+1; ni <= n; ni++) {
            rst *= ni;
            for (int mi = 2; mi <= n - m; mi++) {
                if (rst % mi == 0 && m_array[mi] != 1) {
                    rst /= mi;
                    m_array[mi] = 1;
                }
            }
        }

        return rst;
    }
    void Test() {
        GenerateCase();

        FILE* fin, * fout;
        fin = fopen("program_4_1.in", "rb");
        fout = fopen("program_4_1.out", "wb");
        int n, m;
        while (fscanf(fin, "%d %d", &n, &m) == 2) {
            fprintf(fout, "Combinations: %2d!/%2d!(%2d)!=%lld\n", n, m, n - m, Combinations(n, m));
            fprintf(fout, "CmbntsFrcRed: %2d!/%2d!(%2d)!=%lld\n", n, m, n - m, CombinationsFractionReduction(n, m));
            fprintf(fout, "CmbntsFRdAll: %2d!/%2d!(%2d)!=%lld\n", n, m, n - m, CombinationsFractionReductionAll(n, m));
        }
        fclose(fin);
        fclose(fout);
    }
}

namespace program_4_3_prime {
    /*
    * 素数判定。编写函数，参数是一个正整数 n，如果它是素数，返回 1，否则返回 0。
    */
    #define MAX_NUM                 (9999999999)
    void GenerateCase() {
        freopen("program_4_3.in", "wb", stdout);
        int case_cnt = 50;

        srand((unsigned int)time(NULL));
        for (int cc = 0; cc < case_cnt; cc++) {
            unsigned long long num = rand() % MAX_NUM + 1;
            printf("%lld\n", num);
        }
    }

    int IsPrime(unsigned long long num) {
        for (unsigned long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return 0;
            }
        }
        return 1;
    }

    int IsPrimeInt(int num) {
        if (num <= 1) {
            return 0;
        }

        int max_check_num = floor(sqrt(num) + 0.5); // 防止 i * i > MAX_INT(MAX_UNSIGNED_LONG_LONG)
        for (int i = 2; i <= max_check_num; i++) {
            if (num % i == 0) {
                return 0;
            }
        }

        return 1;
    }
    void Test() {
        GenerateCase();

        freopen("program_4_3.in", "rb", stdin);
        freopen("program_4_3.out", "wb", stdout);

        unsigned long long num = 0;
        while (scanf("%lld", &num) == 1) {
            printf("%d %d\n", IsPrime(num), IsPrimeInt(num));
        }
    }
}

namespace program_4_5_swap {
#include <stdio.h>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}
/*
* 传递地址 program 4_6
* void swap(int *a, int *b) {
*     int t = *a;
*     *a = *b;
*     *b = t;
* }
*/
int main() {
    int a = 3, b = 4;
    swap(3, 4); // 此处应该是书中的误笔，书中想写的应该是 swap(a, b);
    // swap(&a, &b); // 传递地址 program 4_6
    printf("%d %d\n", a, b);
    return 0;
}
}

namespace program_4_7_sum_of_array {
    /*
    * 计算数组元素和（误）
    */
    int sum(int a[]) {
        int ans = 0;

        for (int i = 0; i < sizeof(a); i++) { // int a[] => int *a ==> sizeof(int *) != 数组 a 的大小
            ans += a[i];
        }

        return ans;
    }

    // 修改方案：直接传入数组大小
    int sum_array(int a[], int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i;
        }
        return ans;
    }

    // 思考题：多维数组该如何传递参数？
    // 参考：https://blog.csdn.net/wokaowokaowokao12345/article/details/52999502
}

namespace program_4_9_sum_of_part_array {
    /*
    * 计算左闭右开区间内的元素和（一维，两种写法）
    */
    // 写法一
    int sum(int* begin, int* end) {
        int size = end - begin;
        int rst = 0;
        
        for (int i = 0; i < size; i++) {
            rst += *(begin + i);
        }

        return rst;
    }
    // 写法二
    int sum(int* begin, int* end) {
        int rst = 0;

        for (int* p = begin; p != end; p++) { 
            rst += *p;
        }

        return rst;
    }
}
int main() {
    // program_4_1_combinations::Test();
    // program_4_3_prime::Test();
    return 0;
}