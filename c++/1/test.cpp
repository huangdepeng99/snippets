/*
 * test.cpp
 * 该程序用来验证程序 negative_base.cpp 计算的正确性
 */
/* $begin test.cpp */
#include <iostream>

using namespace std;

int main(void) {
	long long n = 13610324415, base = -7, weight = 1, res = 0;
	while (n) {
		res += weight * (n % 10);
		weight *= base;
		n /= 10;
	}
	cout << res << endl;
	
	return 0;
}

/* $end test.cpp */
