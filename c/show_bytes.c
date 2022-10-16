/*
 *  show_bytes.c
 *  打印程序对象的字节表示
 */
/* $begin show_bytes.c */
#include <stdio.h>

#define show_bytes(ptr, type)						\
do {												\
	unsigned char *p_ = (unsigned char *) (ptr);	\
	size_t len_ = sizeof(type);						\
	for (size_t i = 0; i < len_; ++i)				\
		printf(" %.2X", p_[i]);						\
	putchar('\n');									\
} while(0)

int main(void) {
	int i = 0x102cbf79;
	show_bytes(&i, int);
	float f = 3.1415f;
	show_bytes(&f, float);
	int *p = &i;
	show_bytes(&p, int *);
	
	return 0;
}

/* $end show_bytes.c */
