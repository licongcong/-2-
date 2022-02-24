#ifndef  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif // ! _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <set>
#include <iostream>
using namespace std;

namespace competition_3_1_tex_quotes {
    /*
    * TeX 中的引号（Tex Quotes, UVa 272)
    * 在 TeX 中，左双引号是 “``”，右双引号是 “''”。
    * 输入一篇包含双引号的文章，你的任务是把它转换成 TeX 的格式。
    * 样例输入：
    *   "To be or not to be," quoth the Bard, "that
    *   is the question".
    * 样例输出：
    *   `` To be or not to be,'' quoth the Bard, ``that 
    *   is the question''.
    */
    #define MAX_WORDS_CNT       (1000)    
    #define MAX_CHARACTER_CNT   (10)
    void GenerateCase() {
        FILE* fout;
        fout = fopen("competition_3_1.in", "wb");
        int case_cnt = 50;
        for (int i = 0; i < 50; i++) {
            int quote_flag = 0;
            int word_cnt = rand() % MAX_WORDS_CNT;
            int quote = 0;
            int quote_cnt = 0;
            for (int j = 0; j < word_cnt; j++) {
                int character_cnt = rand() % MAX_CHARACTER_CNT + 1;
                quote = rand() % 2;
                if (quote == 1) {
                    if (quote_flag == 0) {
                        if (j == 0) {
                            fprintf(fout, "\"");
                        } else {
                            fprintf(fout, " \"");
                        }
                        quote_flag = 1;
                    } else {
                        fprintf(fout, "\" ");
                        quote_flag = 0;
                    }
                    quote_cnt++;
                } else {
                    if (j != 0) {
                        fprintf(fout, " ");

                    }
                }

                for (int k = 0; k < character_cnt; k++) {
                    fprintf(fout, "%c", rand() % 26 + 'a');
                }
            }
            if ((quote_cnt & 1) == 1) {
                fprintf(fout, "\"");
            }
            fprintf(fout, "\n");
        }
        fclose(fout);
    }

    void TexQuotes() {
        FILE *fin, *fout;
        fin = fopen("competition_3_1.in", "rb");
        fout = fopen("competition_3_1.out", "wb");

        char chr = '\0';
        int quote_flag = 0;
        while (fscanf(fin, "%c", &chr) == 1) {
            if (chr == '\"') {
                if (quote_flag == 0) {
                    fprintf(fout, "``");
                    quote_flag = 1;
                } else {
                    fprintf(fout, "''");
                    quote_flag = 0;
                }
            } else {
                fprintf(fout, "%c", chr);
            }

        }

        fclose(fin);
        fclose(fout);
    }

    void Test() {
        GenerateCase();
        TexQuotes();
    }
}
int main() {
    competition_3_1_tex_quotes::Test();
    return 0;
}