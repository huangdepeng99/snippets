/*
 *  create_table.c
 *  为 log2_s2.c 生成宏 LOG2
 */
/* $begin create_table.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static
int compar(const void *p1, const void *p2) {
	return * (const int *) p1 - * (const int *) p2;
}

int main() {
	int m = 32;
	while (1) {
		int rem[32] = {};
		for (int i = 0; i < 32; ++i) {
			rem[i] = (1U << i) % m;
		}
		
		qsort(rem, 32, sizeof(int), compar);
		for (int i = 0; i < 31; ++i) {
			if (rem[i] == rem[i + 1])
				goto next;
		}
		break;
next:
		++m;
	}
	
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
