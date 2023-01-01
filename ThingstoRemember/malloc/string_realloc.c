#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//char ***string_print(char ***str)
//	memcpy(*str[0], "Praveen V\0", 10);
char ***string_print(char **str)
{
	memcpy(str[0], "Praveen V\0", 10);

	return ;
}

int main()
{
	char ***result;

	char **str;// here its kind a equivalent to char *argv[]

	str = (char **)malloc(sizeof(char *)*2);  // here 2 indicates 2 (char*)
	str[0]=(char *)malloc(sizeof(char)*10);   // here 10 indicates 10 (char)
	strcpy(str[0],"abcdefghij\0");   // 10 length character 
	
	str[0]=(char *)realloc(str[0], 2*sizeof(char)*10);   // <same as above>
	str[1] = str[0] + 11;
	strcpy(str[1],"xyzlmnopqr\0");   // 10 length character

	printf("%s\n",str[0]);    // to print the string in case of c++
	printf("%s\n",str[1]);    // to print the string in case of c++

	//result = string_print(&str);
	result = string_print(str);
	printf("%s\n",str[0]);    // to print the string in case of c++
}
