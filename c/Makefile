SHELL = /bin/bash
CFLAGS = -Wall -Werror -Og
CC = gcc
TARGETS = add_int32 add_uint32

.PHONY: all clean

all: $(TARGETS)

add_int32: add_int32.c
	@$(CC) $(CFLAGS) -std=c2x -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c2x -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c2x -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c2x $^ -o $@

add_uint32: add_uint32.c
	@$(CC) $(CFLAGS) -std=c2x -E $^ | grep -ve '^#' | indent --linux-style -o $@.i
	@$(CC) $(CFLAGS) -std=c2x -S $^ -o $@.s
	@$(CC) $(CFLAGS) -std=c2x -c $^ -o $@.o
	$(CC) $(CFLAGS) -std=c2x $^ -o $@

clean:
	rm -rvf *.i *.s *.o $(TARGETS)
