/*
 *  set_duplicate_s1.c
 *  判断一个整数集合中是否含有重复元素
 *  (方法1) 暴力求解，该算法在最坏情况下的时间复杂度为Θ(n^2)
 */
/* $begin set_duplicate_s1.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>	/* for bool, true, false */

#define RED(S)		"\033[01;31m" S "\033[00m"
#define ERRMSG(S)	RED(S)
#define N			USHRT_MAX
#define M			100

typedef unsigned short ushrt;

int main(void) {
	double clock_ticks = 0.0;
	for (int i = 0; i < M; ++i) {
		/* 生成数据 */
		int *a = (int *) malloc(sizeof(int) * N);
		if (a == NULL) {
			fprintf(stderr, ERRMSG("Out of memory!\n"));
			return 1;	/* 异常退出 */
		}
		
		srand(time(NULL) + i);
		for (ushrt i = 0; i < N; ++i) {
			a[i] = rand();
		}
		
		/* 进行判断 */
		bool flag;
		clock_t t = clock();
		for (ushrt i = 0; i < N - 1; ++i) {
			for (ushrt j = i + 1; j < N; ++j) {
				if (a[i] == a[j]) {
					flag = true;
					goto outer;
				}
			}
		}
		flag = false;
outer:	
		clock_ticks += clock() - (double) t;

		if (flag == true)
			printf("%d: duplicate elements.\n", i + 1);
		else
			printf("%d: no duplicate elements.\n", i + 1);

		free(a);
	}
	printf("%.0lf clicks, %.6lf seconds.\n", clock_ticks,  clock_ticks / CLOCKS_PER_SEC);
	
	return 0;
}

/* $end set_duplicate_s1.c */
