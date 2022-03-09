#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 10


int rec_calc(int num)
{
	char value = num;
	/* XXX: Things to remember - we can't assign varable to static variable
	static int offset; it will throw compilation error */

	static int offset;
	offset = num; // XXX : To avoid the above issue we need assign this way

	offset++;

	printf("in function : offset: %d\n", offset);
}

int main(int argc, char *argv[])
{
	char dst[10];

	if(argc !=2) {
		fprintf(stderr, "%d: ./a.out needs input", argc);
		exit(-1);
	}

	rec_calc(atoi(argv[1]));
	rec_calc(atoi(argv[1]));
	rec_calc(atoi(argv[1]));
	rec_calc(atoi(argv[1]));
	rec_calc(atoi(argv[1]));
}
