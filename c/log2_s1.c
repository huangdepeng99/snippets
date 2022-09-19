/*
 *  log2_s1.c
 *  求 floor(log2(x))，其中 x 为32位无符号整数
 */
/* $begin log2_s1.c */
#include <stdio.h>
#include <stdint.h>

int floor_log2(uint32_t x) {
	int n = 31;
	if (x <= 0x0000ffff) n -= 16, x <<= 16;
	if (x <= 0x00ffffff) n -=  8, x <<=  8;
	if (x <= 0x0fffffff) n -=  4, x <<=  4;
	if (x <= 0x3fffffff) n -=  2, x <<=  2;
	if (x <= 0x7fffffff) n --;
	return n;
}

#define TEST_CASE(X) printf("%d\n", floor_log2(X))

int main() {
	TEST_CASE(UINT32_MAX);
	TEST_CASE(UINT16_MAX);
	TEST_CASE(UINT8_MAX);
	TEST_CASE(1);
	
	return 0;
}

/* $end log2_s1.c */
