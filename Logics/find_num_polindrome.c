#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_poli(int number)
{
	int temp = 0, remainder = 0, num = number;

	while(num !=0) {
		remainder = num % 10;
		temp = temp*10 + remainder;
		num /=10;
	}

	if(temp != number || number < 0)
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "Missing parameter to ./a.out");
		exit(-1);
	}

	printf("\n %s \n", find_poli(atoi(argv[1])) ? "ploindrome" : "Not a polindrome");

	return 0;
}
