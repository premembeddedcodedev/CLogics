#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//https://www.youtube.com/watch?v=JQ1_7eEPloI

struct hash {
	int id;
	int value;
};


bool getcharcount(char p[])
{
	char array[128];
	char *s = p;
	int count = 0, i;

	memset(array, 0, sizeof(array));
	//if(s) //TODO: need to see what is it
	
	//*s++ or s++ will increment the address and value at address may not change

	while(*s!='\0') {
		array[*s] = array[*s]+1;
		s++;
	}

	for(i=97; i<128; i++)
		if(array[i]%2 != 0)
			count++;

	if(count > 1)
		return false;

	return true;
}

int checkpolindrome(char s[])
{
	int l = 0, r = strlen(s)-1;
	char temp;
	int count = 0, k;

	printf("Checking polindrome....");

	while(l < r) {
		if(s[l] != s[r]) {
			k = r;
			while(l<k && (s[l] != s[k]))
				k--;
			if(l==k) {
				temp = s[l+1];
				s[l+1] = s[l];
				s[l] = temp;
				count++;
			} else {
				while(k < r) {
					temp = s[k];
					s[k] = s[k+1];
					s[k+1] = temp;
					k++;
					count++;
				}
				l++;
				r--;
			}
		} else {
			l++;
			r--;
		}
	}

	printf("\t Here's the string: %s\n", s);

	return count;
}

int swap_palindrome(char s[])
{
	if(!getcharcount(s))
		return -1;
	
	printf("initial polindrome check.... Done!\n");

	return checkpolindrome(s);
}	

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "./a.out need params \n");
		exit(-1);	
	}
	printf("%d ",swap_palindrome(argv[1]));
}
