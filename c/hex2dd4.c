/* 
 * hex2dd4.c
 * 将十六进制表示的IPv4地址转换为点分十进制串
 */
/* $begin hex2dd4.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>		/* 为了 `struct in_addr' 和 INET_ADDRSTRLEN */
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	struct in_addr addr;
	uint32_t temp;
	sscanf(argv[1], "%x", &temp);
	addr.s_addr = htonl(temp);
	char name[INET_ADDRSTRLEN];
	const char *rv = inet_ntop(AF_INET, &addr.s_addr, name, INET_ADDRSTRLEN);
	if (rv == NULL) {
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}
	puts(name);
	
	exit(EXIT_SUCCESS);
}

/* $end hex2dd4.c */
