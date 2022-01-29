#ifndef  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif // ! _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

namespace space_2_1_daffodil {
    /* 
    * 输出 100 - 999 中的所有水仙花数。
    * 若三位数 ABC 满足 ABC = A^3 + B^3 + C^3，则称其为水仙花数。
    * 如：153=1^3+5^3+3^3，所以 153 是水仙花数
    */
    void daffodil() {
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 100; i <= 999; i++) {
            a = i / 100;
            b = (i - a * 100) / 10;
            c = i % 10;

            a = a * a * a;
            b = b * b * b;
            c = c * c * c;
            if (a + b + c == i) {
                printf("%d\n", i);
            }
        }
    }
    void test() {
        daffodil();
    }
}

namespace space_2_2_hanxin {
    /*
    * 相传韩信才智过人，从不直接清点自己军队的人数，只要让士兵先后以三人一排、五人一排、七人一排得变换队形，
    * 而他每次只掠一眼排尾就知道总人数了。
    * 输入包含多组数组，每组数据包含3个非负整数 a, b, c，表示每种队形排尾的人数（a<3, b<5, c<7），
    * 输出总人数的最小值（或报告无解）。
    * 已知总人数不少于10人，不超过100人。输入到文件结束为止
    * * * 样例输入：
    * * * 2 1 6
    * * * 2 1 3
    * * * 样例输出：
    * * * Case 1: 41
    * * * Case 2: No answer
    */
    void generateCase() {
        FILE* fin;
        fin = fopen("2_2_data.in", "wb");
        int a, b, c;
        for (int i = 0; i < 50; i++) {
            a = rand() % 3;
            b = rand() % 5;
            c = rand() % 7;
            fprintf(fin, "%d %d %d\n", a,b,c);
        }

        fclose(fin);

    }
    void hanxin() {
        FILE* fin, * fout;
        fin = fopen("2_2_data.in", "rb");
        fout = fopen("2_2_data.out", "wb");
        int no_answer = 1;
        int a, b, c;
        int case_cnt = 0;
        while (fscanf(fin, "%d %d %d\n", &a, &b, &c) == 3) {
            case_cnt++;
            no_answer = 1;
            for (int i = 10; i <= 100; i++) {
                if (i % 3 == a && i % 5 == b && i % 7 == c) {
                    fprintf(fout, "Case %d: %d\n", case_cnt, i);
                    no_answer = 0;
                    break;
                }
            }

            if (no_answer == 1) {
                fprintf(fout, "Case %d: No answer\n", case_cnt);
            }
        }

        fclose(fin);
        fclose(fout);
    }

    void test() {
        generateCase();
        hanxin();
    }
}

namespace space_2_3_triangle {
    /*
    * 输入正整数 n<=20，输出一个 n 层的倒三角。
    * 例如：n = 5 时，输出如下：
    * #########
    *  #######
    *   #####
    *    ###
    *     #
    */


    void triangle(unsigned int n) {
        unsigned int space_cnt = 0;
        unsigned int hashtag_cnt = 0;
        for (unsigned int i = 0; i < n; i++) {
            space_cnt = i;
            hashtag_cnt = 2 * (n - i) - 1;
            
            for (unsigned int j = 0; j < space_cnt; j++) {
                printf("%c", ' ');
            }
            
            for (unsigned int j = 0; j < hashtag_cnt; j++) {
                printf("%c", '#');
            }
            printf("\n");
        }
    }

    void test() {
        triangle(5);
        triangle(7);
        triangle(4);
    }
}

namespace space_2_4_subsequence {
    /*
    * 输入两个正整数 n<m<10^6，输出 1/n^2+1/(n+1)^2 + ... + 1/m^2。保留5位小数
    * 输入包含多组数据，结束标志为 n=m=0。提示：本题有陷阱
    * * * 样例输入：
    * * * 2 4
    * * * 65536 655360
    * * * 0 0
    * * * 样例输出：
    * * * Case 1: 0.42361
    * * * Case 2: 0.00001
    */

    void generateCase() {
        FILE* fout;
        fout = fopen("2_4_data.in", "wb");
        int n, m;
        for (int i = 0; i < 50; i++) {
            n = rand() % 999998 + 1;
            m = rand() % (999999 - n) + 1;
            m = n + m;

            fprintf(fout, "%d %d\n", n, m);
        }
        fprintf(fout, "0 0\n");
        fclose(fout);
    }

    void subsequence() {
        FILE* fin, * fout;
        fin = fopen("2_4_data.in", "rb");
        fout = fopen("2_4_data.out", "wb");
        
        int case_cnt = 0;
        unsigned int n, m;
        while (fscanf(fin, "%d %d\n", &n, &m) == 2) {
            if (n == 0 && m == 0) {
                break;
            }

            case_cnt++;

            double rst = 0.0;
            for (unsigned int i = n; i <= m; i++) {
                rst += double(1.0) / (double(i) * double(i));
            }

            fprintf(fout, "Case %d: %.5f\n", case_cnt, rst);
        }

        fclose(fin);
        fclose(fout);
    }

    void test() {
        generateCase();
        double start_time = clock();
        subsequence();
        printf("Subsequence Time used: %f\n", ((double)clock() - start_time) / CLOCKS_PER_SEC);

    }
}

namespace space_2_5_decimal {
    /*
    * 输入正整数 a, b, c，输出 a/b 的小数形式，精确到小数点后 c 位。
    * a,b <= 10^6, c <= 100。
    * 输入包含多组数据，结束标记为 a=b=c=0
    * 
    * * * 样例输入：
    * * * 1 6 4
    * * * 0 0 0
    * * * 样例输出：
    * * * Case 1: 0.1667
    */

    void generateCase() {
        FILE* fout;
        fout = fopen("2_5_data.in", "wb");

        int a, b, c;
        for (int i = 0; i < 50; i++) {
            a = rand() % 1000000 + 1;
            b = rand() % 1000000 + 1;
            c = rand() % 101;
            fprintf(fout, "%d %d %d\n", a, b, c);
        }
        fprintf(fout, "0 0 0\n");
        fclose(fout);
    }
    
    void decimal() {
        FILE* fin, * fout;
        fin = fopen("2_5_data.in", "rb");
        fout = fopen("2_5_data.out", "wb");

        int a, b, c;
        int case_cnt = 0;
        while (fscanf(fin, "%d %d %d\n", &a, &b, &c)) {

            if (a == 0 && b == 0 && c == 0) {
                break;
            }

            case_cnt++;

            double div_rst = double(a) / double(b);
            fprintf(fout, "Case %d: %.*f\n", case_cnt, c, div_rst);
        }

        fclose(fin);
        fclose(fout);
    }

    void test() {
        generateCase();
        decimal();
    }
}

namespace space_2_6_permutation {
    /*
    * 使用 1,2,3,...,9 组成3个三位数 abc, def 和 ghi。每个数字恰好使用一次，
    * 要求 abc:def:ghi = 1:2:3。按照 "abc def ghi"的格式输出所有解，每个解
    * 一行。提示：不必太动脑筋。
    */

    void permutation() {
        FILE* fout;
        fout = fopen("2_6_data.out", "wb");
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                if (a == b) {
                    continue;
                }
                for (int c = 1; c <= 3; c++) {
                    if (a == c || b == c) {
                        continue;
                    }
                    int abc = a * 100 + b * 10 + c;
                    fprintf(fout, "%d %d %d\n", abc, 2 * abc, 3 * abc);
                }
            }
        }
        fclose(fout);
    }

    void test() {
        permutation();
    }
}

namespace space_2_question_1 {
    /*
    * 假设需要输出 2, 4, 6, 8, ... , 2n，每个一行，能不能通过对程序 2-1 进行一个小小的
    * 改动来实现呢？
    * * 1. #include <stdio.h>
    * * 2. int main() 
    * * 3. {
    * * 4.     int n;
    * * 5.     scanf("%d", &n);
    * * 6.     for (int i=1; i <= n; i++) 
    * * 7.         printf("%d\n", i);
    * * 8.     return 0;
    * * 9. }
    * 
    * 
    * 任务1：修改第7行，不修改第6行
    * * * printf("%d\n", 2*i);
    * 任务2：任性第6行，不修改第7行
    * * * for (int i=2; i <= 2*n; i+=2)
    */
}

namespace space_2_question_2 {
    /*
    * 下面程序的运行结果是什么？
    * #include <stdio.h>
    * int main() {
    *     double i;
    *     for (i = 0; i != 10; i+=0.1)
    *         printf("%.1f\n", i);
    *     return 0;
    * }
    * 
    * Ans: 死循环
    */
}

int main() {
    // space_2_1_daffodil::test();
    // space_2_2_hanxin::test();
    // space_2_3_triangle::test();
    // space_2_4_subsequence::test();
    // space_2_5_decimal::test();
    // space_2_6_permutation::test();

    return 0;
}