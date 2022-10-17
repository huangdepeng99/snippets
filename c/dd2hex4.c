/* 
 * dd2hex4.c
 * 将IPv4地址的点分十进制表示转换为十六进制表示
 */
/* $begin dd2hex4.c */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>		/* 为了 `struct in_addr' */
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <dotted-decimal>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	struct in_addr addr;
	int rv = inet_pton(AF_INET, argv[1], &addr.s_addr);
	if (rv != 1) {
		if (rv == 0)
			fputs("Not in presentation format\n", stderr);
		else
			perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	printf("%#x\n", ntohl(addr.s_addr));
	
	exit(EXIT_SUCCESS);
}

/* $end dd2hex4.c */
