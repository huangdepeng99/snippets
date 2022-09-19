/*
 *  log2_s2.c
 *  求 floor(log2(x))，其中 x 为32位无符号整数，且为2的整数次幂
 */
/* $begin log2_s2.c */
#include <stdio.h>
#include <stdint.h>

/* 宏LOG2由 create_table.c 生成 */
#define LOG2(X) ("-01J2GK-3@HNL;-=47A-IFO?M:<6-E>95D8CB"[(X) % 37] - '0')

#define TEST_CASE(X) printf("%d\n", LOG2(X))

int main() {
	TEST_CASE(1U << 31);
	TEST_CASE(1U << 15);
	TEST_CASE(1U << 7);
	TEST_CASE(1U << 0);
	
	return 0;
}

/* $end log2_s2.c */
