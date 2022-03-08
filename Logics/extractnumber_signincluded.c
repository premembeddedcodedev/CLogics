#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int myatoi(char *s)
{
	printf("in function %s\n", s);
	int num = 0, intend = 0;
	char *c = s;
	bool sign_present = false;

#if 0
	if(c >= '0' && c <= '9')
		printf("Exist\n");
	else
		printf("does not Exist\n");

	printf("Difference: %d\n", ('A' - '0'));

	while(*s!='\0') {
		*s++;
		num++;
	}
	return num;
#endif	
	while(*s != '\0') {
		if(*s == '-')
			sign_present = true;

		if(*s >= '0' && *s <= '9')
			intend = intend * 10 + (*s - '0');
		*s++;
	}
#if 0
	while(*s == ' ') *c++;
	if(*s == '-') {
		sign_present = true;
		//c++;
		*s++;
	}
	while(*s >= '0' && *s <= '9') {
		intend = intend * 10 + (*s - '0');
		*s++;
		//c++;
		//*s++; //TODO: need to see difference between *c++ vs c++ ==> both are same
		//intend = *s * 10 + intend;
	}
#endif
	if(sign_present)
		intend *= -1;
	return intend;
}

int main(int argc, char **argv)
{
	if(argc != 2) {
		fprintf(stderr, "./a.out require input file");
		exit(-1);
	}

	printf("atoi output: %d\n", myatoi(argv[1]));

	return 0;
}
