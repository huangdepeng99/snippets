/* 
 * hex2ch.c
 * 将十六进制表示的IPv6地址转换为冒分十六进制串
 */
/* $begin hex2ch.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <netinet/in.h>		/* 为了 `struct in6_addr' 和 INET6_ADDRSTRLEN */
#include <arpa/inet.h>
#include <regex.h>

#define RED(S)		"\033[01;31m" S "\033[00m"
#define ERRMSG(S)	RED(S)
#define PATTERN		"^(0x|0X)?[[:xdigit:]]{1,32}$"
#define s6_addr32	__in6_u.__u6_addr32

static char *program_name;

void
print_usage(void)
{
	fprintf(stderr, "usage: %s <hex number>\n", program_name);
}

int
Regcomp(regex_t *restrict compiled, const char *restrict pattern, int cflags)
{
	int rv = regcomp(compiled, pattern, cflags);
	if (rv != 0) {
		size_t length = regerror(rv, compiled, NULL, 0);
		char buffer[length];
		regerror(rv, compiled, buffer, length);
		fprintf(stderr, "regcomp: %s\n", buffer);
		exit(EXIT_FAILURE);
	}
	return rv;
}

int
Regexec(const regex_t *restrict compiled, const char *restrict string, size_t nmatch,
		regmatch_t matchptr[restrict], int eflags)
{
	int rv = regexec(compiled, string, nmatch, matchptr, eflags);
	if (rv != 0 && rv != REG_NOMATCH) {
		size_t length = regerror(rv, compiled, NULL, 0);
		char buffer[length];
		regerror(rv, compiled, buffer, length);
		fprintf(stderr, "regcomp: %s\n", buffer);
		exit(EXIT_FAILURE);
	}
	return rv;
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
	regex_t compiled;
	Regcomp(&compiled, PATTERN, REG_EXTENDED | REG_NOSUB);
	int rv = Regexec(&compiled, argv[1], 0, NULL, 0);
	if (rv == REG_NOMATCH) {
		fprintf(stderr, ERRMSG("Error: ") "invalid hex number \"%s\"\n", argv[1]);
		print_usage();
		exit(EXIT_FAILURE);
	}
	regfree(&compiled);
	
	char *start;
	if (argv[1][0] == '0' && (argv[1][1] == 'X' || argv[1][1] == 'x')) {
		start = argv[1] + 2;
	} else {
		start = argv[1];
	}
	char buf[INET6_ADDRSTRLEN];
	size_t len = strlen(start);
	memset(buf, '0', 32 - len);
	strcpy(buf + (32 - len), start);
	
	struct in6_addr addr;
	uint32_t temp;
	sscanf(buf + 24, "%x", &temp); addr.s6_addr32[3] = htonl(temp); buf[24] = '\0';
	sscanf(buf + 16, "%x", &temp); addr.s6_addr32[2] = htonl(temp); buf[16] = '\0';
	sscanf(buf +  8, "%x", &temp); addr.s6_addr32[1] = htonl(temp); buf[8]  = '\0';
	sscanf(buf +  0, "%x", &temp); addr.s6_addr32[0] = htonl(temp); buf[0]  = '\0';
	
	char chstr[INET6_ADDRSTRLEN];
	Inet_ntop(AF_INET6, addr.s6_addr32, chstr, INET6_ADDRSTRLEN);
	puts(chstr);
	
	exit(EXIT_SUCCESS);
}

/* $end hex2ch.c */
