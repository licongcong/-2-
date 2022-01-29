#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
ofstream fout;
namespace space_1_1_average {
    /*
    * ��������������������ǵ�ƽ��ֵ������ 3 λС����
    */
    void average(int num1, int num2, int num3) {
        double sum = double(num1) + double(num2) + double(num3);
        printf("%.3f\n", sum / 3.0);
        return;
    }
}

namespace space_1_2_temperature {
    /*
    * ���뻪�����϶�f�������Ӧ�������¶�c������ 3 λС������ʾ��c=5(f-32)/9
    */
    void temperature(double f) {
        double c = 5.0 * (f - 32.0) / 9.0;
        printf("%.3f\n", c);
        return;
    }
}

namespace space_1_3_sum {
    /*
    * ����һ�������� n����� 1+2+3+...+n ��ֵ����ʾ��Ŀ���ǽ�����⣬������ϰ���
    */
    void sumFromOne2N(unsigned int n) {
        unsigned long long sum = 0;
        for (unsigned int i = 0; i <= n; i++) {
            sum += i;
        }
        printf("%lld\n", sum);
        return;
    }
    
    void sumOfArithmeticSequence(unsigned int n) {
        unsigned long long sum = (unsigned long long (n) * (unsigned long long(n) + 1)) >> 1;
        printf("%lld\n", sum);
        return;
    }
}

namespace space_1_4_sin_cos {
    /*
    * ���������� n��n < 360������� n �ȵ����ҡ����Һ���ֵ����ʾ��ʹ����ѧ������
    */

    /*
    * sin(x) = x - x^3/3! + x^5/5! + ... + (-1)^n*x^{2n+1}/(2n+1)!
    */
    double sin(unsigned int n) {
        double rst = n;
        double term = n;
        double acc = 0.000001;

        double termIdx = 1.0;
        double sign = 1.0;
        double powerN = n;
        double factorial = 1.0;
        while (abs(term) > acc) {
            sign = -1 * sign;
            powerN = powerN * n * n;
            factorial = factorial * (2 * termIdx) * (2 * termIdx + 1);
            term = sign * powerN / factorial;
            rst += term;
        }

        return rst;
    }

    /*
    * cosx = 1 - x^2/2! + x^4/4! + ... + (-1)^n * x^{2n} / (2n)!
    */
    double cos(unsigned int n) {
        double rst = 1.0;
        double term = 1.0;
        double acc = 0.000001;

        double termIdx = 1.0;
        double sign = 1.0;
        double powerN = 1.0;
        double factorial = 1.0;
        while (abs(term) > acc) {
            sign = -1 * sign;
            powerN = powerN * n * n;
            factorial = factorial * (2 * termIdx - 1) * (2 * termIdx);
            term = sign * powerN / factorial;
            rst += term;
        }

        return rst;
    }

    void sinAndCos(int n) {
        printf("%.3f, %.3f\n", ::sin(n), ::cos(n));
    }
}

namespace space_1_5_discount {
    /*
    * һ���·�95Ԫ����������300Ԫ�����Դ�����ۡ����빺���·������������Ҫ֧���Ľ���λ��Ԫ����������λС����
    */
    void discount(unsigned int n) {
        double total_money = 95.0 * n;
        if (total_money > 300.0) {
            total_money = total_money * 0.85;
        }
        printf("%f Ԫ\n", total_money);
    }
}

namespace space_1_6_triangle {
    /*
    * ���������ε�3���ߵĳ��ȣ���Ϊ�����������ж��Ƿ���Ϊֱ�������ε�3���߳���
    * ������ԣ����yes��������ܣ���� no��
    * ��������޷����������Σ������ not a triangle.
    */
    void trianlge(unsigned int a, unsigned int b, unsigned int c) {
        
        if (a + b > c && a + c > b && b + c > a) { // �ж��Ƿ��ܹ���������
            unsigned int pow2a = a * a;
            unsigned int pow2b = b * b;
            unsigned int pow2c = c * c;
            if (pow2a + pow2b == pow2c || pow2a + pow2c == pow2b || pow2b + pow2c == pow2a) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            printf("not a triangle\n");
        }
    }
}

namespace space_1_7_year {
    /*
    * ������ݣ��ж��Ƿ�Ϊ���ꡣ����ǣ������ yes��������� no.
    * ��ʾ�����жϳ��� 4 �������ǲ����ġ�
    */
    void year(int n) {
        if (n % 400 == 0) {
            printf("yes\n");
        } else if (n % 4 == 0 && n % 100 != 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
int main() {

    return 0;
}