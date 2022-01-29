#ifndef  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif // ! _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

namespace space_2_1_daffodil {
    /* 
    * ��� 100 - 999 �е�����ˮ�ɻ�����
    * ����λ�� ABC ���� ABC = A^3 + B^3 + C^3�������Ϊˮ�ɻ�����
    * �磺153=1^3+5^3+3^3������ 153 ��ˮ�ɻ���
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
    * �ഫ���Ų��ǹ��ˣ��Ӳ�ֱ������Լ����ӵ�������ֻҪ��ʿ���Ⱥ�������һ�š�����һ�š�����һ�ŵñ任���Σ�
    * ����ÿ��ֻ��һ����β��֪���������ˡ�
    * ��������������飬ÿ�����ݰ���3���Ǹ����� a, b, c����ʾÿ�ֶ�����β��������a<3, b<5, c<7����
    * �������������Сֵ���򱨸��޽⣩��
    * ��֪������������10�ˣ�������100�ˡ����뵽�ļ�����Ϊֹ
    * * * �������룺
    * * * 2 1 6
    * * * 2 1 3
    * * * ���������
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
    * ���������� n<=20�����һ�� n ��ĵ����ǡ�
    * ���磺n = 5 ʱ��������£�
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
    * �������������� n<m<10^6����� 1/n^2+1/(n+1)^2 + ... + 1/m^2������5λС��
    * ��������������ݣ�������־Ϊ n=m=0����ʾ������������
    * * * �������룺
    * * * 2 4
    * * * 65536 655360
    * * * 0 0
    * * * ���������
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
    * ���������� a, b, c����� a/b ��С����ʽ����ȷ��С����� c λ��
    * a,b <= 10^6, c <= 100��
    * ��������������ݣ��������Ϊ a=b=c=0
    * 
    * * * �������룺
    * * * 1 6 4
    * * * 0 0 0
    * * * ���������
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
    * ʹ�� 1,2,3,...,9 ���3����λ�� abc, def �� ghi��ÿ������ǡ��ʹ��һ�Σ�
    * Ҫ�� abc:def:ghi = 1:2:3������ "abc def ghi"�ĸ�ʽ������н⣬ÿ����
    * һ�С���ʾ������̫���Խ
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
    * ������Ҫ��� 2, 4, 6, 8, ... , 2n��ÿ��һ�У��ܲ���ͨ���Գ��� 2-1 ����һ��СС��
    * �Ķ���ʵ���أ�
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
    * ����1���޸ĵ�7�У����޸ĵ�6��
    * * * printf("%d\n", 2*i);
    * ����2�����Ե�6�У����޸ĵ�7��
    * * * for (int i=2; i <= 2*n; i+=2)
    */
}

namespace space_2_question_2 {
    /*
    * �����������н����ʲô��
    * #include <stdio.h>
    * int main() {
    *     double i;
    *     for (i = 0; i != 10; i+=0.1)
    *         printf("%.1f\n", i);
    *     return 0;
    * }
    * 
    * Ans: ��ѭ��
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