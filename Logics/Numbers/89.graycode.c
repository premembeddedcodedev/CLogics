//89.gray code
// https://www.youtube.com/watch?v=ha1gEWYvr78&list=PLEI-q7w3s9gRV3Bn3VO1rtgkA0wNkIm-y&index=1
// output 
// N = 0, 0
// N = 1, 2^0 = 1 {0 (prev)} => 0, 1
// N = 2, 2^1 = 2 {0,1} => 3, 2
// N = 3, 2^2 = 4 {0,1,3,2} => 0, 1, 3, 2, 6, 7, 5, 4



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_gray_code(int n)
{
	int a[20], i, j, len = sizeof(a), k = 0;

	memset(a, 0, sizeof(a));

	j = 1;

	a[k++] = 0;
	a[k++] = 1;

	for(i = 2; i<=n; i++) {
		j *= 2;
		len = k;
		while(len-1 >= 0) {
			a[k] = j + a[len-1];
			len--;
			k++;
		}
	}

	len = 0;
	while(len < k)
		printf("%d ", a[len++]);
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "./a.out has in-sufficient args %d\n", argc);
		exit(-1);
	}

	print_gray_code(atoi(argv[1]));
}
