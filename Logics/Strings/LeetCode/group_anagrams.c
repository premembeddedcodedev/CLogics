#include <stdio.h>
#include <string.h>

char *** groupAnagrams(char str[][5], int strsSize, int* returnSize, int** returnColumnSizes)
{

		
}

int main(int argc, char *argv[])
{
	int num_srings, i=0, strlen2, len = 0;

	printf("Enter the num.of strings : \n");
	scanf("%d", &num_srings);
	printf("Enter the strings len : \n");
	scanf("%d", &strlen2);
	int *num;

	char str[num_srings][strlen2], ***dest;

	printf("Enter the strings:\n");
	while(i<num_srings)
		scanf("%s", str[i++]);
		//gets(str[i++]);
		//fgets(str[i++], strlen2, stdin);
	i = 0;
	while(i<num_srings)
		printf("%s\t", str[i++]);

	//char *ste = str;
	//char *ste[2] = {"prem", "praveen"};
	//char *stw = ste;


	dest = groupAnagrams(str, strlen2, &len, &num);

	return 0;
}
