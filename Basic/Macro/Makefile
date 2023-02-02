CC=gcc
CFLAGS=-g

all: test

test: test.c
	$(CC) $(CFLAGS) -DARRAY_LENGTH=24 $< -o $@

clean:
	$(RM) test
	$(RM) -r *.dSYM
