SHELL = /bin/bash
CFLAGS = -Wall -Werror -Og
CC = gcc
TARGETS = add_int32 add_uint32 log2_s1 create_table log2_s2 set_duplicate_s1 set_duplicate_s2 set_duplicate_s3

.PHONY: all clean

all: $(TARGETS)

add_int32: add_int32.c
	@$(CC) $(CFLAGS) -std=c2x -fwrapv -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c2x -fwrapv -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c2x -fwrapv -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c2x -fwrapv $^ -o $@

add_uint32: add_uint32.c
	@$(CC) $(CFLAGS) -std=c2x -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c2x -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c2x -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c2x $^ -o $@

log2_s1: log2_s1.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -o $@

create_table: create_table.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ -lm | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -lm -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -lm -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -lm -o $@

log2_s2: log2_s2.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -o $@

set_duplicate_s1: set_duplicate_s1.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -o $@

set_duplicate_s2: set_duplicate_s2.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -o $@

set_duplicate_s3: set_duplicate_s3.c
	@$(CC) $(CFLAGS) -std=c11 -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c11 -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c11 -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c11 $^ -o $@

clean:
	rm -rvf *.i *.s *.o $(TARGETS)
