/*
 *  set_duplicate_s2.c
 *  判断一个整数集合中是否含有重复元素
 *  (方法2) 首先使用快速排序对集合排序，再进行比较，该算法在平均情况下的时间复杂度为Θ(nlogn)
 *  注：log以2为底
 */
/* $begin set_duplicate_s2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>	/* for bool, true, false */

#define N USHRT_MAX
#define M 100

typedef unsigned short ushrt;

static
int compar(const void *p1, const void *p2) {
	return * (const int *) p1 - * (const int *) p2;
}

int main(void) {
	double clock_ticks = 0.0;
	for (int i = 0; i < M; ++i) {
		/* 生成数据 */
		int *a = (int *) malloc(sizeof(int) * N);
		if (a == NULL) {
			fprintf(stderr, "\033[01;31m" "Out of memory!\n" "\033[00m");
			return 1;	/* 异常退出 */
		}
		
		srand(time(NULL));
		for (ushrt i = 0; i < N; ++i) {
			a[i] = rand();
		}
		
		/* 进行判断 */
		bool flag;
		clock_t t = clock();
		qsort(a, N, sizeof(int), compar);
		for (ushrt i = 0; i < N - 1; ++i) {
			if (a[i] == a[i + 1]) {
				flag = true;
				goto outer;
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
		sleep(1);
	}
	printf("%.0lf clicks, %.6lf seconds.\n", clock_ticks,  clock_ticks / CLOCKS_PER_SEC);
	
	return 0;
}

/* $end set_duplicate_s2.c */