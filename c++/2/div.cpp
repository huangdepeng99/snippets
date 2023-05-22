/*
 * div.cpp
 * 标准库函数 std::div 用来计算向零取整的整数除法的商和余数，从 C++11 开始，
 * 该函数的行为与内建运算符 / 和 % 一致。
 * 在该文件中，函数 div_floor 实现了向下取整的整数除法，而函数 div_ceil 实现
 * 了向上取整的整数除法。
 */
/* $begin div.cpp */
#include <iostream>
#include <cstdlib>

using namespace std;

void print_div_t(const div_t & d) {
	cout << d.quot << ", " << d.rem << endl;
}

div_t div_floor(int x, int y) {
	if ((x ^ y) >= 0) return div(x, y);
	int q = y < 0 ? -((x - y - 1) / (-y)) : -((-x + y - 1) / y);
	int r = x - q * y;
	return { q, r };
}

div_t div_ceil(int x, int y) {
	if ((x ^ y) < 0) return div(x, y);
	int q = y < 0 ? (-x - y - 1) / (-y) : (x + y - 1) / y;
	int r = x - q * y;
	return { q, r };
}

int main(void) {
	print_div_t(div(1, 26));			// 0, 1
	print_div_t(div(-1, -26));			// 0, -1
	print_div_t(div(-1, 26));			// 0, -1
	print_div_t(div(1, -26));			// 0, 1
	print_div_t(div(0, 26));			// 0, 0
	print_div_t(div(0, -26));			// 0, 0
	cout << endl;
	print_div_t(div_floor(1, 26));		// 0, 1
	print_div_t(div_floor(-1, -26));	// 0, -1
	print_div_t(div_floor(-1, 26));		// -1, 25
	print_div_t(div_floor(1, -26));		// -1, -25
	print_div_t(div_floor(0, 26));		// 0, 0
	print_div_t(div_floor(0, -26));		// 0, 0
	cout << endl;
	print_div_t(div_ceil(1, 26));		// 1, -25
	print_div_t(div_ceil(-1, -26));		// 1, 25
	print_div_t(div_ceil(-1, 26));		// 0, -1
	print_div_t(div_ceil(1, -26));		// 0, 1
	print_div_t(div_ceil(0, 26));		// 0, 0
	print_div_t(div_ceil(0, -26));		// 0, 0
	
	return 0;
}

/* $end div.cpp */
