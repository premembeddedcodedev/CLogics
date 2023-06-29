/*
https://leetcode.com/problems/detect-capital/
Reference : TechDose from youtube
*/

#include<stdio.h>
#include<stdbool.h>
#include <string.h>

bool is_upper(char c)
{
	if((c >= 'A') && (c <= 'Z'))
		return true;

	return false;
}	

bool detectcapital(char *str, int len)
{
	int i = 0, count = 0;

	while(str[i] != '\0') {
		if(is_upper(str[i]))
			count++;
		i++;
	}

	if(((count == len) || (count == 1)) && is_upper(str[0]) || count == 0)
		return true;
	else
		return false;
}

int main()
{
	char *str = "sA";

	printf("length : %ld\n", strlen(str));

	printf("Detected Capital: %s\n", detectcapital(str, strlen(str)) ? "Yes" : "No");

	return 0;
}
