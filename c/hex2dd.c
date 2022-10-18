/* 
 * hex2dd.c
 * 将十六进制表示的IPv4地址转换为点分十进制串
 */
/* $begin hex2dd.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>		/* 为了 `struct in_addr' 和 INET_ADDRSTRLEN */
#include <arpa/inet.h>

static char *program_name;

void
print_usage(void)
{
	fprintf(stderr, "usage: %s <hex number>\n", program_name);
}

const char *
Inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
	const char *rv = inet_ntop(af, src, dst, size);
	if (rv == NULL) {
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}
	return rv;
}

int
main(int argc, char *argv[])
{
	program_name = argv[0];
	if (argc != 2) {
		print_usage();
		exit(EXIT_FAILURE);
	}
	struct in_addr addr;
	uint32_t temp;
	sscanf(argv[1], "%x", &temp);
	addr.s_addr = htonl(temp);
	char ddstr[INET_ADDRSTRLEN];
	Inet_ntop(AF_INET, &addr.s_addr, ddstr, INET_ADDRSTRLEN);
	puts(ddstr);
	
	exit(EXIT_SUCCESS);
}

/* $end hex2dd.c */
