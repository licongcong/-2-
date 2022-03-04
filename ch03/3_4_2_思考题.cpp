#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
using namespace std;

namespace Question_3_4_2_1 {
    /*
    * 题目 1（必要的存储量）：数组可以用来保存很多数据，但在一些情况下，并不需要把数据保存下来。
    * 下面哪些题目可以不借助数组，哪些必须借助数组？请编程实现。假设输入只能读一遍。
    * * 输入一些数，统计个数。
    * * 输入一些数，求最大值，最小值和平均数。
    * * 输入一些数，哪两个数最接近。
    * * 输入一些数，求第二大的数。
    * * 输入一些数，求它们的方差。
    * * 输入一些数，统计不超过平均数的个数。
    */

    /*
    * 输入一些数，统计个数。
    * ==> 不需要借助数组，边读边统计即可。
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
    * 输入一些数，求最大值，最小值和平均数。
    * ==> 不需要
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
    * 输入一些数，哪两个数最接近。
    * ==> 需要。
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
    * 输入一些数，求第二大的数。
    * ==> 不需要。
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
    * 输入一些数，求它们的方差。
    * ==> 需要。
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
    * 输入一些数，统计不超过平均数的个数。
    * ==> 需要。
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
    * 题目 2（统计字符 1 的个数）：下面的程序意图在于统计字符串中字符 1 的个数，可惜有瑕疵：
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
    * 该程序至少有 3 个问题，其中一个导致程序无法运行，另一个导致结果不正确，还有一个导致效率低下。
    * 你能找到它们并改正么？
    * 
    * ==>
    * 程序无法运行：strlen() 在头文件 string.h 当中，程序没有 include 该头文件
    * 导致结果不正确：统计字符串中 1 的个数时，应该使用 s[i] == '1'
    * 效率低下：可以不使用 s[maxn] 存储，边读边统计即可
    * 其他：
    * * * #define maxn 10000000 + 10 ==> #define maxn (10000000 + 10)
    * * * int main() {...} 但是没有返回值。
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