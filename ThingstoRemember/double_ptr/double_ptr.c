#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
	char **str;                              // here its kind a equivalent to char *argv[]

	str = (char **)malloc(sizeof(char *)*2);  // here 2 indicates 2 (char*)
	str[0]=(char *)malloc(sizeof(char)*10);   // here 10 indicates 10 (char)
	str[1]=(char *)malloc(sizeof(char)*10);   // <same as above>

	strcpy(str[0],"abcdefghij");   // 10 length character 
	strcpy(str[1],"xyzlmnopqr");   // 10 length character

	printf("%s\n",str[0]);    // to print the string in case of c++
	printf("%s\n",str[1]);    // to print the string in case of c++
}
