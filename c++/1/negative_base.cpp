/*
 * negative_base.cpp
 * 计算一个正整数的负七进制数
 */
/* $begin negative_base.cpp */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
	long long n = 195132894, base = -7;
	
	vector<int> res;
	while (n) {
		long long q = n > 0 ? n / base : (-n + (-base) - 1) / (-base);
		res.push_back(n - q * base);
		n = q;
	}
	copy(res.rbegin(), res.rend(), ostream_iterator<int>(cout, ""));
	cout << endl;
	
	return 0;
}

/* end negative_base.cpp */
