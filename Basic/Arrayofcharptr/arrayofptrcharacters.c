#include <stdio.h>
/* TODO: array of 5 pointers pointer size is 8 bytes.. its taking only 8 bytes @max
 * 
 * input:
 * 12345678
12345678
12345678
12345678
12345678
Output Strings are:
1. String are below
1234567812345678123456781234567812345678 (5 times printed because of offset given as 0)
12345678123456781234567812345678 (4 times printed because of offset given as 1) 
123456781234567812345678 (3 times printed because of offset given as 2)
1234567812345678 (2 times printed because of offset given as 1)
12345678 (1 times printed because of offset given as 1)
2. String are below
1234567812345678123456781234567812345678
12345678123456781234567812345678
123456781234567812345678
1234567812345678
12345678

if we are giving more than 8 chars/bytes. it hits stack smash like below

input Strings are:
123456789
123456789
123456789

123456789
123456789
Output Strings are:
1. String are below
12345678123456781234567812345678123456789
123456781234567812345678123456789
1234567812345678123456789
12345678123456789
123456789
2. String are below
12345678123456781234567812345678123456789
123456781234567812345678123456789
1234567812345678123456789
12345678123456789
123456789
*** stack smashing detected ***: terminated ==================> here's generating fault because of pointer size
Aborted (core dumped)


 *
 *
 * */

int main()
{
	char *A[5];
	int i;

	printf("input Strings are: \n");

	for(i=0; i<5; i++) {
		scanf("%s", (char *)&A[i]);
	}

	/*TODO: Warinings need to fix --> warning removed by typecasting all places but we cant give string more than some chars*/
	printf("Output Strings are: \n");

	//TODO: Need to see why &A[i] printing required string due to pointer pointing to address?
	printf("1. String are below\n");
	for(i=0; i<5; i++) {
		printf("%s\n", (char *)&A[i]); //char * typecasting giving any result here ? ..but no change
	}

	printf("2. String are below\n");
	for(i=0; i<5; i++) {
		printf("%s\n", (char *)&A[i]);
	}

	//printf("3. String are below\n");

	/*TODO : Seg Fault
	for(i=0; i<5; i++) {
		printf("%s\n", A[i]);
	}*/

	return 0;
}
