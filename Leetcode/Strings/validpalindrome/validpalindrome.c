
/* https://leetcode.com/problems/valid-palindrome/
 * */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

bool is_alphanumeric(char c)
{
	if((c>= '0' && c<= '9'))
		return true;

	if((c>= 'a' && c<= 'z'))
		return true;

	if((c>= 'A' && c<= 'Z'))
		return true;

	return false;
}

bool check_compare_Lowerupper(int ci, int cj)
{
	if((ci>= 'A' && ci<= 'Z') && ((ci == cj) || (cj == ci + 32)))
		return true;

	if((ci>= 'a' && cj<= 'z') && ((ci == cj) || (cj == ci - 32)))
		return true;

	return false;
}

bool is_palindrome(char *str)
{
	bool status = false;
	int i = 0, j = strlen(str) - 1;

	if(j == 0)
		return true;

	while(i<j) {
		if(!is_alphanumeric(str[i])) {
			i++;
			continue;
		} 
		
		if(!is_alphanumeric(str[j])) {
			j--;
			continue;
		} 
		
		if(check_compare_Lowerupper(str[i], str[j])) {
			status = true;
		} else
			return false;

		i++;
		j--;
	}

	return status;
}

int main()
{
	char *str = "race a car"; 
	//char *str = "A man, a plan, a canal: Panama";//"race a car"; 
	//char *str = " ";//"race a car"; 

	printf("Valid palindrome : %s\n", is_palindrome(str) ? "true" : "false");

	char c = 'a';

	int d = c;

	printf("a:: %d\n", d);

	return 0;
}
