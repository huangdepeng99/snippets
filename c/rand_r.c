/*
 *  rand_r.c
 *  伪随机数生成器 srand、rand、rand_r 的一种实现
 *  注：参见手册页 rand(3)
 */
/* $begin rand_r.c */
#define RAND_MAX 32767

typedef unsigned int seed_t;

static unsigned long next_seed = 1;

void srand(seed_t seed) {
	next_seed = seed;
}

int rand(void) {
	next_seed = next_seed * 1103515245 + 12345;
	return ((unsigned) (next_seed >> 16) % (RAND_MAX + 1));
}

int rand_r(seed_t *seedp) {
	unsigned long next_seed = *seedp;
	*seedp = next_seed * 1103515245 + 12345;
	return ((unsigned) (next_seed >> 16) % (RAND_MAX + 1));
}

/* $end rand_r.c */
