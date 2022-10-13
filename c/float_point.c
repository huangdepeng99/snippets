/*
 *  float_point.c
 *  IEEE 754 浮点数使用有限的位来表示实数，因此其只能表示实数的一个很小的子集；因为舍入的存在，
 *  IEEE 754 浮点数往往只是实数的一个近似值，而不是其精确值；如果两个实数是相等的，那么它们的
 *  IEEE 754 浮点数表示也一定是相等的，但反之不成立
 */
/* $begin float_point.c */
#include <stdio.h>

int main(void) {
	printf("%d\n", 1e10f == 1e10f);				/* 1 */
	printf("%d\n", 1e10f == 1e10f + 1.0f);		/* 1 */
	printf("%d\n", 1e10f == 1e10f + 2.0f);		/* 1 */
	printf("%d\n", 1e10f == 1e10f + 1e5f);		/* 0 */
	
	return 0;
}

/* $end float_point.c */
