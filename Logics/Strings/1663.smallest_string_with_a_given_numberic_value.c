//https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

void small_stron_given_num_value(int num, int sum, char str[])
{
	int j = num - 1;
	printf("num: %d sum: %d\n", num, sum);

	sum = sum - num;

	memset(str, 'a', num);
	
	while(sum > 0) {
		if(sum < MAX) {
			str[j] = (char) ('a' + sum);
			sum = 0;
		} else {
			str[j] = 'z';
			sum -= MAX;
		}
		j--;
	}
}

int main(int argc, char *argv[])
{
	int i = 0;

	char str[10] = {0};

	if(argc != 3) {
		fprintf(stderr, "./a.out is not having sufficient args %d\n", argc);
		exit(-1);
	}

	small_stron_given_num_value(atoi(argv[1]), atoi(argv[2]), str);

	while(i < 3)
		printf("%c\t", str[i++]);

	return 0;
}
