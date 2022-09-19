/*
 *  create_table.c
 *  为 log2_s2.c 生成宏 LOG2
 */
/* $begin create_table.c */
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int m = 32;
	while (1) {
		int rem[32] = {};
		for (int i = 0; i < 32; ++i) {
			rem[i] = (1U << i) % m;
		}
		
		for (int i = 0; i < 31; ++i) {
			for (int j = i + 1; j < 32; ++j) {
				if (rem[i] == rem[j])
					goto l1;
			}
		}
		goto l2;
l1:
		++m;
	}
l2:
	;
	char magic[m + 1];
	memset(magic, '-', m), magic[m] = '\0';
	char base = '0';
	for (int i = 0; i < 32; ++i) {
		magic[(1U << i) % m] = floor(log2(1U << i)) + base;
	}
	
	printf("#define LOG2(X) (\"%s\"[(X) %% %d] - \'%c\')\n", magic, m, base);
	
	return 0;
}

/* $end create_table.c */
