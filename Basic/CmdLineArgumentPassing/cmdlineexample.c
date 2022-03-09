#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "Missing parameter to ./a.out");
		exit(-1);
	}

	printf("%d", atoi(argv[1])); //XXX: with atoi, we can this as integer and pass it as int in fucntion argument.
	printf("%s", argv[1]); //XXX: without atoi converion it will give char argv[], we can pass the same and get it done the work

	return 0;
}
