#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
using namespace std;

namespace Question_3_4_2_1 {
    /*
    * ��Ŀ 1����Ҫ�Ĵ洢���������������������ܶ����ݣ�����һЩ����£�������Ҫ�����ݱ���������
    * ������Щ��Ŀ���Բ��������飬��Щ����������飿����ʵ�֡���������ֻ�ܶ�һ�顣
    * * ����һЩ����ͳ�Ƹ�����
    * * ����һЩ���������ֵ����Сֵ��ƽ������
    * * ����һЩ��������������ӽ���
    * * ����һЩ������ڶ��������
    * * ����һЩ���������ǵķ��
    * * ����һЩ����ͳ�Ʋ�����ƽ�����ĸ�����
    */

    /*
    * ����һЩ����ͳ�Ƹ�����
    * ==> ����Ҫ�������飬�߶���ͳ�Ƽ��ɡ�
    */

#define MAX_NUMS_CNT    (1000)
#define MAX_NUM     (100)
#define MIN_NUM         (-1)

    void GenerateCase() {
        FILE* fout;
        fout = fopen("3_4_2_1.in", "wb");

        int rand_cnt = rand() % MAX_NUMS_CNT + 1;
        for (int i = 0; i < rand_cnt; i++) {
            fprintf(fout, "%lf ", double(rand() % 100000) / 1000.0);
        }

        fclose(fout);
    }
    void Count() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");

        double num = 0;
        int num_cnt = 0;
        while (fscanf(fin, "%lf", &num) == 1) {
            num_cnt++;
        }

        printf("%d\n", num_cnt);
        fclose(fin);
    }

    /*
    * ����һЩ���������ֵ����Сֵ��ƽ������
    * ==> ����Ҫ
    */
    void GetMaxMinAverage() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");

        double max_num = MIN_NUM;
        double min_num = MAX_NUM;
        double num_cnt = 0;
        double sum_num = 0;
        double num = 0;
        while (fscanf(fin, "%lf", &num) == 1) {
            if (num > max_num) {
                max_num = num;
            }

            if (num < min_num) {
                min_num = num;
            }

            sum_num += num;
            num_cnt++;
        }

        printf("%lf %lf %lf\n", max_num, min_num, sum_num / num_cnt);
        fclose(fin);
    }

    /*
    * ����һЩ��������������ӽ���
    * ==> ��Ҫ��
    */
    void quickSort(double input[MAX_NUMS_CNT], int first, int last) {
        int pivot;
        int i;
        int j;
        double temp;

        if (first < last) {
            pivot = first;
            i = first;
            j = last;

            while (i < j) {
                while (input[i] <= input[pivot] && i < last) {
                    i++;
                }
                while (input[j] > input[pivot]) {
                    j--;
                }
                if (i < j) {
                    temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                }
            }

            temp = input[pivot];
            input[pivot] = input[j];
            input[j] = temp;

            quickSort(input, first, j - 1);
            quickSort(input, j + 1, last);
        }
    }

    void CloserNum() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");

        double nums[MAX_NUMS_CNT] = { 0 };
        double num = 0;
        int num_cnt = 0;
        while (fscanf(fin, "%lf", &num) == 1) {
            nums[num_cnt] = num;
            num_cnt++;
        }

        quickSort(nums, 0, num_cnt - 1);

        double delta = MAX_NUM;
        double first = 0, second = 0;
        for (int i = 1; i < num_cnt; i++) {
            if (nums[i] - nums[i - 1] < delta) {
                first = nums[i - 1];
                second = nums[i];
                delta = nums[i] - nums[i - 1];
            }
        }

        printf("%lf, %lf\n", first, second);

        fclose(fin);
    }

    /*
    * ����һЩ������ڶ��������
    * ==> ����Ҫ��
    */
    void GetSecondNumber() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");
        double max_num = MIN_NUM;
        double second_max_num = MIN_NUM;
        double num = 0;

        while (fscanf(fin, "%lf", &num) == 1) {
            if (num == max_num) {
                continue;
            }

            if (num > max_num) {
                second_max_num = max_num;
                max_num = num;
                continue;
            }

            if (num > second_max_num) {
                second_max_num = num;
            }
        }

        printf("%lf\n", second_max_num);

        fclose(fin);
    }

    /*
    * ����һЩ���������ǵķ��
    * ==> ��Ҫ��
    */
    void GetVariance() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");

        double nums[MAX_NUMS_CNT] = { 0 };
        int num_cnt = 0;
        double sum_num = 0;
        double average = 0;
        double variance = 0;

        while (fscanf(fin, "%lf", &nums[num_cnt]) == 1) {
            sum_num += nums[num_cnt++];
        }

        average = sum_num / double(num_cnt);

        for (int i = 0; i < num_cnt; i++) {
            variance += (nums[i] - average) * (nums[i] - average);
        }

        printf("%lf\n", variance / double(num_cnt));

        fclose(fin);
    }

    /*
    * ����һЩ����ͳ�Ʋ�����ƽ�����ĸ�����
    * ==> ��Ҫ��
    */
    void GetCount() {
        FILE* fin;
        fin = fopen("3_4_2_1.in", "rb");

        double nums[MAX_NUMS_CNT] = { 0 };
        int num_cnt = 0;
        double sum_num = 0;
        double average = 0;
        int count = 0;
        
        while (fscanf(fin, "%lf", &nums[num_cnt]) == 1) {
            sum_num += nums[num_cnt++];
        }

        average = sum_num / double(num_cnt);

        for (int i = 0; i < num_cnt; i++) {
            if (nums[i] <= average) {
                count++;
            }
        }

        printf("%d\n", count);
        fclose(fin);
    }

    void Test() {
        GenerateCase();
        Count();
        GetMaxMinAverage();
        CloserNum();
        GetSecondNumber();
        GetVariance();
        GetCount();
    }
}

namespace Question_3_4_2_2 {
    /*
    * ��Ŀ 2��ͳ���ַ� 1 �ĸ�����������ĳ�����ͼ����ͳ���ַ������ַ� 1 �ĸ�������ϧ��覴ã�
    * #include <stdio.h>
    * #define maxn 10000000 + 10
    * int main() {
    *     char s[maxn];
    *     scanf("%s", s);
    *     int tot = 0;
    *     for(int i=0; i < strlen(s); i++)
    *         if(s[i] == 1) tot++;
    *     printf("%d\n", tot);
    * }
    * 
    * �ó��������� 3 �����⣬����һ�����³����޷����У���һ�����½������ȷ������һ������Ч�ʵ��¡�
    * �����ҵ����ǲ�����ô��
    * 
    * ==>
    * �����޷����У�strlen() ��ͷ�ļ� string.h ���У�����û�� include ��ͷ�ļ�
    * ���½������ȷ��ͳ���ַ����� 1 �ĸ���ʱ��Ӧ��ʹ�� s[i] == '1'
    * Ч�ʵ��£����Բ�ʹ�� s[maxn] �洢���߶���ͳ�Ƽ���
    * ������
    * * * #define maxn 10000000 + 10 ==> #define maxn (10000000 + 10)
    * * * int main() {...} ����û�з���ֵ��
    */

    #include <stdio.h>
    #include <string.h>
    
    void GenerateCase() {
        FILE* fout;
        fout = fopen("3_4_2_2_2.in", "wb");
        
        int str_len = rand() % 10000000 + 1;
        for (int i = 0; i < str_len; i++) {
            fprintf(fout, "%c", rand() % 10 + '0');
        }
        fprintf(fout, "\n");

        fclose(fout);
    }
    int main() {
        FILE* fin = fopen("3_4_2_2_2.in", "rb");

        int one_cnt = 0;
        char chr = '\0';
        while (fscanf(fin, "%c", &chr) == 1) {
            if (chr == '1') {
                one_cnt++;
            }
        }

        printf("%d\n", one_cnt);
        return 0;
    }

    void Test() {
        GenerateCase();
        main();
    }
}

int main() {
    Question_3_4_2_1::Test();
    Question_3_4_2_2::Test();
    return 0;
}