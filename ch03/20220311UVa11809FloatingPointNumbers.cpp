/*
* https://vjudge.net/problem/UVA-11809
*/

#include <stdio.h>
#include <math.h>

#define MAX_FLOATING_POINT_NUMBER_LENGTH    (300)
#define MAX_MANTISSA_BIT_CNT				(9)
#define MAX_EXPONENT_BIT_CNT				(30)

int main() {

	// freopen("20220311UVa11809FloatingPointNumbers.in", "rb", stdin);
	// freopen("20220311UVa11809FloatingPointNumbers.out", "wb", stdout);

	double a, b;
	while ((scanf("%17lfe%lf", &a, &b)) && (a != 0)) {
		// printf("%.15lf %lf\n", a, b);
		double sum_log2_a_blog2_10 = log2(a) + (b) * log2(10);
		// printf("log2(%.15lf)+%.15lf*log2(10) = %.15lf\n", a, b, sum_log2_a_blog2_10);

		double max_exponent = ceil(sum_log2_a_blog2_10);
		// printf("max exponent = %lf\n", max_exponent);

		int exponent_bit_cnt = 1;
		while (int(pow(2, exponent_bit_cnt) - 1) < max_exponent && exponent_bit_cnt <= MAX_EXPONENT_BIT_CNT) {
			exponent_bit_cnt++;
		}

		double mantissa = pow(2, sum_log2_a_blog2_10 - (pow(2.0, exponent_bit_cnt) - 1)) - 0.5;
		// printf("log2_mantissa = %.15lf\n", mantissa);
		int mantissa_bit_cnt = 1;
		double sum_pow_2_x = 0;
		while (sum_pow_2_x < mantissa && mantissa_bit_cnt < (MAX_MANTISSA_BIT_CNT+1)) {
			sum_pow_2_x += pow(2.0, -(++mantissa_bit_cnt));
		}

		printf("%d %d\n", mantissa_bit_cnt - 1, exponent_bit_cnt);

	}

	return 0;
}