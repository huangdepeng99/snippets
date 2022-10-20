/* 
 * ch2hex.c
 * 将IPv6地址的冒分十六进制表示转换为十六进制表示
 */
/* $begin ch2hex.c */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>		/* 为了 `struct in6_addr' */
#include <arpa/inet.h>

static char *program_name;

void
print_usage(void)
{
	fprintf(stderr, "usage: %s <colon-hexadecimal>\n", program_name);
}

int
Inet_pton(int af, const char *src, void *dst)
{
	int rv = inet_pton(af, src, dst);
	if (rv != 1) {
		if (rv == 0)
			fputs("Not in presentation format\n", stderr);
		else
			perror("inet_pton");
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
	struct in6_addr addr;
	Inet_pton(AF_INET6, argv[1], addr.s6_addr32);
	fputs("0x", stdout);
	for (int i = 0; i < 4; ++i) {
		printf("%08x", ntohl(addr.s6_addr32[i]));
	}
	putchar('\n');
	
	exit(EXIT_SUCCESS);
}

/* $end ch2hex.c */
