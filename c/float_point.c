/*
 *  float_point.c
 *  IEEE 754 浮点数使用有限的位来表示实数，因此其只能表示实数的一个很小的子集；因为舍入的存在，
 *  IEEE 754 浮点数往往只是实数的一个近似值，而不是其精确值；如果两个实数是相等的，那么它们的
 *  IEEE 754 浮点数表示也一定是相等的，但反之不成立
 */
/* $begin float_point.c */
#include <stdio.h>
#include <float.h>

union { double d; unsigned long ul; } z;

int main(void) {
	printf("1e10f == 1e10f ? %d\n", 1e10f == 1e10f);					/* 1 */
	printf("1e10f == 1e10f + 1.0f ? %d\n", 1e10f == 1e10f + 1.0f);		/* 1 */
	printf("1e10f == 1e10f + 2.0f ? %d\n", 1e10f == 1e10f + 2.0f);		/* 1 */
	printf("1e10f == 1e10f + 1e5f ? %d\n", 1e10f == 1e10f + 1e5f);		/* 0 */
	
	printf("1e38f == 1e38f + 1e30f ? %d\n", 1e38f == 1e38f + 1e30f);	/* 1 */
	printf("1e38f == 1e38f + 1e31f ? %d\n", 1e38f == 1e38f + 1e31f);	/* 0 */
	
	z.d = 0.0;		/* +0.0 */
	printf("%.1f (%#lX)\n", z.d, z.ul);
	z.d = -0.0;		/* -0.0 */
	printf("%.1f (%#lX)\n", z.d, z.ul);
	printf("0.0 == -0.0 ? %d\n", 0.0 == -0.0);	/* 1 */
	
	double a = 1.0 / 0.0;		/* +Inf */
	double b = -1.0 / 0.0;		/* -Inf */
	printf("1.0 / 0.0 = %f\n", a);
	printf("-1.0 / 0.0 = %f\n", b);
	printf("DBL_MAX = %G\n", DBL_MAX);
	printf("+Inf > DBL_MAX ? %d\n", a > DBL_MAX);
	printf("DBL_MIN = %G\n", DBL_MIN);
	printf("-Inf < DBL_MIN ? %d\n", b < DBL_MIN);
	
	double x = 0.0 / 0.0;		/* NaN */
	printf("0.0 / 0.0 = %f\n", x);
	printf("NaN != NaN ? %d\n", x != x);		/* IEEE 754 中的 NaN 满足表达式 x != x */
	
	return 0;
}

/* $end float_point.c */
