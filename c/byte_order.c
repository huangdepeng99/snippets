/*
 *  byte_order.c
 *  判断机器的字节顺序
 */
/* $begin byte_order.c */
#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint32_t u = 0x1U;
	puts(*((unsigned char *) &u) == 0 ? "big-endian" : "little-endian");
	
	return 0;
}

/* $end byte_order.c */
