#include<stdio.h>
#include<string.h>


void subparition(char *s, char *target, int index)
{
	int i, size = 0;
	static int j = 0, k = 0;

	if(index >= strlen(s)) {
		return;
	}

	target[j] = s[index];
	j += 1;
	index += 1;

	subparition(s, target, index);
		for(int i=0; i<j; i++)
			printf("%c", target[i]);
	--j;
	subparition(s, target, index);

	return;
}

int main()
{
	char *str = "ABCDEFG";
	char dest[10];

	subparition(str, dest, 0);

	return 0;
}
