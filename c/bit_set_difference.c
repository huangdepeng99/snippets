/*
 *  bit_set_difference.c
 *  求两个位集合的差集 ( A - B = A - A ∩ B )，这两个位集合用32位无符号整数表示，
 *  其中每一位都对应一个集合元素，为1则表示该元素存在，为0则表示该元素不存在，就
 *  比如：
 *      #define OPTION1  (1U << 0)
 *      #define OPTION2  (1U << 1)
 *      ......
 *      #define OPTION32 (1U << 31)
 *      ......
 *      foo(&var, 1,  OPTION1 | OPTION2 | OPTION15);
 *  在这个例子中，函数 foo 通过宏 OPTION1 ~ OPTION31 来控制它的选项的开关，32位
 *  无符号整数中的每一位都对应一个选项，为1则表示开启了这个选项，为0则没开启
 *  (方法) 根据命题公式 A - B 的真值表求出其主析取范式即可，具体步骤如下：
 *      命题公式 A - B 的真值表为：
 *      A | B | A - B
 *      0 | 0 |   0
 *      0 | 1 |   0
 *      1 | 0 |   1
 *      1 | 1 |   0
 *      根据表中的成真赋值可以算出主析取范式为 m2，即 A ∧ ￢B，当然，也可以
 *      算出主合取范式，但是该命题公式的主析取范式恰好是最简表达式，已经是
 *      最优解了
 */
/* $begin bit_set_difference.c */
#include <stdio.h>
#include <stdint.h>

uint32_t bit_set_difference(uint32_t a, uint32_t b) {
	return a & ~b;
}

#define TEST_CASE(A, B) printf("%#X - %#X = %#X\n", A, B,  bit_set_difference(A, B))

int main(void) {
	TEST_CASE(UINT32_MAX, 1U);
	TEST_CASE(0xFA192857U, 0xA8745552U);
	TEST_CASE(0x92B6CAA7U, 0x1204DF4AU);
	TEST_CASE(1U, UINT32_MAX);
	
	return 0;
}

/* $end bit_set_difference.c */
