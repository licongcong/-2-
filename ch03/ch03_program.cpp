#ifndef  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif // ! _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <set>
#include <iostream>
using namespace std;


namespace program_3_1_reverse_print {
    /*
    * ��ȡһЩ���������������һ���С�
    * ��֪���������� 100 ����
    */

    void GenerateCase() {
        FILE* fout;
        fout = fopen("program_3_1_data.in", "wb");
        
        int number_cnt = rand() % 100 + 1;
        for (int j = 0; j < number_cnt; j++) {
            fprintf(fout, "%d ", rand() % 100000);
        }

        fclose(fout);
    }

    const int kMaxArrSize = 105;
    int kArr[kMaxArrSize];
    void ReversePrint() {
        FILE* fin, * fout;
        fin = fopen("program_3_1_data.in", "rb");
        fout = fopen("program_3_1_data.out", "wb");

        int j = 0;
        // while (fscanf(fin, "%d ", &kArr[j++])); // j ����һ��
        // ��δ��ļ���ȡ n �����Ȳ�ͬ�� case?
        while (fscanf(fin, "%d ", &kArr[j]) == 1) {
            j++;
        }
        for (int k = j - 1; k >= 0; k--) { 
            fprintf(fout, "%d ", kArr[k]);
        }

        fclose(fin);
        fclose(fout);
    }

    void Test() {
        GenerateCase();
        ReversePrint();
    }
}

namespace program_3_2_bubble {
    /*
    * ��������
    * �� n յ�ƣ����Ϊ 1~n����һ���˰����еƶ��򿪣��ڶ����˰������б��Ϊ
    * 2 �ı����Ŀ��أ���Щ�ƽ����ص������������˰������б��Ϊ 3 �ı����Ŀ�
    * �أ����йص��ĵƽ����򿪣����ŵĵƽ����ص������������ƣ�һ���� k ���ˣ�
    * ���������Щ���ǿ��ŵģ�
    * ���� n �� k��������ŵĵƵı�š� k <= n <= 1000
    * * ��������
    * * 7 3
    * * ������� 
    * * 1 5 6 7
    */

    void GenerateCase() {
        FILE* fout;
        fout = fopen("program_3_2_data.in", "wb");
        fprintf(fout, "%d %d\n", 7, 3);
        for (int i = 0; i < 50; i++) {
            int n = rand() % 1000 + 1;
            int k = rand() % n + 1;
            fprintf(fout, "%d %d\n", n, k);
        }
        fclose(fout);
    }

    const int kMaxBubbleCnt = 1001;
    int kBubble[kMaxBubbleCnt];
    void Bubble() {
        FILE* fin, * fout;
        fin = fopen("program_3_2_data.in", "rb");
        fout = fopen("program_3_2_data.out", "wb");

        int n, k;
        while (fscanf(fin, "%d %d", &n, &k) == 2) {
            memset(kBubble, 0, sizeof(kBubble));

            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= n; j++) {
                    if (j % i == 0) {
                        kBubble[j] = ~kBubble[j];
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                if (kBubble[i] == (~0)) {
                    fprintf(fout, "%d ", i);
                }
            }
            fprintf(fout, "\n");
        }

        fclose(fin);
        fclose(fout);
    }

    void Test() {
        GenerateCase();
        Bubble();
    }
}

namespace program_3_3_serpentine_fill {
    /*
    * ��������
    * �� nxn �ķ��������� 1, 2,..., nxn, Ҫ��������Ρ����磬n=4 ʱ�� ����Ϊ��
    * 10 11 12 1
    * 9  16 13 2
    * 8  15 14 3
    * 7  6  5  4
    * ����ķ����У�����Ŀո�ֻ��Ϊ�˱��ڹ۲���ɣ������ϸ������ n <= 8
    */

    void GenerateCase() {
        FILE* fout;
        fout = fopen("program_3_3_data.in", "wb");
        for (int i = 1; i <= 8; i++) {
            fprintf(fout, "%d\n", i);
        }
        fclose(fout);
    }

    const int kMaxN = 8;
    int kArr[kMaxN][kMaxN];
    void SerpentineFile() {
        FILE* fin, * fout;
        fin = fopen("program_3_3_data.in", "rb");
        fout = fopen("program_3_3_data.out", "wb");

        int n;
        while (fscanf(fin, "%d\n", &n) == 1) {
            memset(kArr, 0, sizeof(kArr));

            int num_cnt = 1;
            int row = 0;
            int col = n - 1;
            while (num_cnt <= n * n) {              // �ҳ��յ�����
                while (row < col) {                 // ����ʱ���յ������� row == col
                    kArr[row++][col] = num_cnt++;
                }

                while (row + col >= n) {            // ����ʱ���յ������� row+col < n��row+col == n-1)
                    kArr[row][col--] = num_cnt++;
                }

                while (row != col) {                // ����ʱ���յ������� row == col
                    kArr[row--][col] = num_cnt++;
                }

                while (kArr[row][col] == 0) {       // ����ʱ���յ����������һ��û�б����ʹ��ĵ�
                    kArr[row][col++] = num_cnt++;
                }

                col--;                              // ����һ�����������ڵ���һ��
                row++;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    fprintf(fout, "%3d ", kArr[i][j]);
                }
                fprintf(fout, "\n");
            }
            fprintf(fout, "\n");

        }
        fclose(fin);
        fclose(fout);
    }

    void Test() {
        GenerateCase();
        SerpentineFile();
    }
}

namespace program_3_4_vertical {
    /*
    * ��ʽ����
    * �ҳ��������� abc*de����λ��������λ��������ʽ��ʹ������������ʽ�У�
    * �������ֶ�����һ���ض������ּ��ϡ�
    * �������ּ��ϣ��������ּ�û�пո񣩣����������ʽ��
    * ÿ����ʽǰӦ����һ����ţ�֮��Ӧ��һ�����С����������������
    * �����ʽ�����������. ��ʾ�ո񣬿��Բ������Ҫ��֤���롣
    * * ��������
    * * 2357
    * * �������
    * * <1>
    * * ..775
    * * X..33
    * * -----
    * * .2325
    * * 2325.
    * * -----
    * * 25575
    * *
    * * The number of solutions = 1
    */

    void GenerateCase() {
        FILE* fout;
        fout = fopen("program_3_4_data.in", "wb");

        for (int i = 0; i < 50; i++) {
            int num = rand() % 10000000;
            string num_str = to_string(num);
            set<char> chr_set(num_str.begin(), num_str.end());
            set<char>::iterator iter;
            for (iter = chr_set.begin(); iter != chr_set.end(); ++iter) {
                fprintf(fout, "%c", *iter);
            }
            fprintf(fout, "\n");
        }
        fclose(fout);
    }


    const int kMaxBufferSize = 100;
    char kBuffer[kMaxBufferSize];
    const int kMaxArrSize = 10;
    char kArr[kMaxArrSize];
    void Vertical() {
        FILE* fin, * fout;
        fin = fopen("program_3_4_data.in", "rb");
        fout = fopen("program_3_4_data.out", "wb");

        int case_cnt = 0;
        int num_of_solution = 0;
        while (fscanf(fin, "%s", kArr) != EOF) {
            case_cnt++;
            num_of_solution = 0;
            fprintf(fout, "Case %d:\n", case_cnt);

            for (int abc = 100; abc <= 999; abc++) {
                for (int de = 10; de <= 99; de++) {
                    int abc_x_de = abc * de;
                    int abc_x_d = abc * (de / 10);
                    int abc_x_e = abc * (de % 10);
                    
                    sprintf(kBuffer, "%d%d%d%d%d", abc, de, abc_x_d, abc_x_e, abc_x_de);

                    int valid = 1;
                    for (int i = 0; i < strlen(kBuffer); i++) {
                        if (strchr(kArr, kBuffer[i]) == NULL) {
                            valid = 0;
                            break;
                        }
                    }

                    if (valid == 1) {
                        num_of_solution++;
                        fprintf(fout, "<%d>\n", num_of_solution);
                        fprintf(fout, "%5d\n", abc);
                        fprintf(fout, "X%4d\n", de);
                        fprintf(fout, "-----\n");
                        fprintf(fout, "%5d\n", abc_x_e);
                        fprintf(fout, "%4d\n", abc_x_d);
                        fprintf(fout, "-----\n");
                        fprintf(fout, "%5d\n", abc_x_de);
                        fprintf(fout, "\n");
                    }
                }
            }

            fprintf(fout, "\nThe number of solutions = %d\n", num_of_solution);
        }

        fclose(fin);
        fclose(fout);
    }

    void Test() {
        GenerateCase();
        Vertical();
    }
}
int main() {
    // program_3_1_reverse_print::Test();
    // program_3_2_bubble::Test();
    // program_3_3_serpentine_fill::Test();
    program_3_4_vertical::Test();
    return 0;
}