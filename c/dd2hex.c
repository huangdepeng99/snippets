/* 
 * dd2hex.c
 * 将IPv4地址的点分十进制表示转换为十六进制表示
 */
/* $begin dd2hex.c */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>		/* 为了 `struct in_addr' */
#include <arpa/inet.h>

static char *program_name;

void
print_usage(void)
{
	fprintf(stderr, "usage: %s <dotted-decimal>\n", program_name);
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
	struct in_addr addr;
	Inet_pton(AF_INET, argv[1], &addr.s_addr);
	printf("0x%08x\n", ntohl(addr.s_addr));
	
	exit(EXIT_SUCCESS);
}

/* $end dd2hex.c */
