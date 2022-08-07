/*
 *  add_int32.c
 *  只使用位运算实现32位有符号整数的加法运算
 *  注：编译时请使用选项 -std=c2x (为了INT64_WIDTH)
 */
/* $begin add_int32.c */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>	/* 为了bool、true、false */

int64_t add_int32(int32_t i1, int32_t i2) {
	int64_t i1_64 = i1;
	int64_t i2_64 = i2;
	int64_t result = 0;
	bool flag = false;	/* 是否进位 */

	for (uint8_t i = 0; i < INT64_WIDTH; ++i) {
		uint8_t x = i1_64 & 0x1;
		uint8_t y = i2_64 & 0x1;
		uint8_t za = x & y;
		uint8_t zo = x | y;
		if (za == 1) {	/* za == 1 */
			if (flag == true) {
				result |= 0x1L << (INT64_WIDTH - 1);
			}
			else {
				result &= ~(0x1L << (INT64_WIDTH - 1));
			}
			flag = true;
		}
		else if (zo == 1) {	/* za != 1 && zo == 1 */
			if (flag == true) {
				result &= ~(0x1L << (INT64_WIDTH - 1));
				flag = true;
			}
			else {
				result |= 0x1L << (INT64_WIDTH - 1);
				flag = false;
			}
		}
		else {	/* za != 1 && zo != 1 */
			if (flag == true) {
				result |= 0x1L << (INT64_WIDTH - 1);
			}
			else {
				result &= ~(0x1L << (INT64_WIDTH - 1));
			}
			flag = false;
		}

		i1_64 >>= 1;
		i2_64 >>= 1;
		if (i != INT64_WIDTH - 1) {
			result >>= 1;
		}
	}
	
	return result;
}

#define TEST_CASE(A, B) printf("%d + %d = %ld\n", A, B, add_int32(A, B))

int main() {
	TEST_CASE(INT32_MIN, INT32_MIN);
	TEST_CASE(INT32_MAX, INT32_MAX);
	TEST_CASE(0, 0);
	TEST_CASE(INT32_MIN / 2, INT32_MIN / 2);
	TEST_CASE(INT32_MAX / 2, INT32_MAX / 2);
	TEST_CASE(0, INT32_MIN / 2);
	TEST_CASE(0, INT32_MAX / 2);
	TEST_CASE(1, INT32_MAX);
	TEST_CASE(-1, INT32_MIN);
	TEST_CASE(INT16_MAX, INT16_MIN);
	TEST_CASE(INT32_MAX, INT32_MIN);
	
	return 0;
}

/* $end add_int32.c */
