/*
 *  add_uint32.c
 *  只使用位运算实现32位无符号整数的加法运算
 *  注：编译时请使用选项 -std=c2x (为了UINT32_WIDTH)
 */
/* $begin add_uint32.c */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>	/* 为了bool、true、false */

uint64_t add_uint32(uint32_t u1, uint32_t u2) {
	bool flag = false;	/* 是否进位 */
	uint64_t result = 0;

	for (uint8_t i = 0; i < UINT32_WIDTH; ++i) {
		uint8_t x = u1 & 0x1;
		uint8_t y = u2 & 0x1;
		uint8_t za = x & y;
		uint8_t zo = x | y;
		if (za == 1) {	/* za == 1 */
			if (flag == true) {
				result |= 0x1UL << (UINT32_WIDTH - 1);
			}
			else {
				result &= ~(0x1UL << (UINT32_WIDTH - 1));
			}
			flag = true;
		}
		else if (zo == 1) {	/* za != 1 && zo == 1 */
			if (flag == true) {
				result &= ~(0x1UL << (UINT32_WIDTH - 1));
				flag = true;
			}
			else {
				result |= 0x1UL << (UINT32_WIDTH - 1);
				flag = false;
			}
		}
		else {	/* za != 1 && zo != 1 */
			if (flag == true) {
				result |= 0x1UL << (UINT32_WIDTH - 1);
			}
			else {
				result &= ~(0x1UL << (UINT32_WIDTH - 1));
			}
			flag = false;
		}

		u1 >>= 1;
		u2 >>= 1;
		if (i != UINT32_WIDTH - 1) {
			result >>= 1;
		}
	}
	
	if (flag == true) {
		result |= 0x1UL << UINT32_WIDTH;
	}
	
	return result;
}

#define TEST_CASE(A, B) printf("%u + %u = %lu\n", A, B, add_uint32(A, B))

int main() {
	TEST_CASE(0, 0);
	TEST_CASE(UINT32_MAX, UINT32_MAX);
	TEST_CASE(UINT32_MAX / 2, UINT32_MAX / 2);
	TEST_CASE(0, UINT32_MAX / 2);
	TEST_CASE(UINT8_MAX, UINT8_MAX);
	TEST_CASE(UINT16_MAX, UINT16_MAX);
	
	return 0;
}

/* $end add_uint32.c */
