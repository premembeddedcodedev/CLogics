#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#if 0
//char ***string_print(char ***str)
//	memcpy(*str[0], "Praveen V\0", 10);
char ***string_print(char **str, char **str2)
{
	//char ***result = (char *** )malloc(sizeof(char **));
	char ***result;
	strcpy(str[0], "Praveen V\0");
#if 0	
	strcpy(str[0], "Praveen V\0");
	**result[0] = str;
	
	strcpy(str2[0], "Prem V\0");
	**result[1] = str2;
	return result;
#endif
	return result = &str;
}
#endif

#if 1
char ***string_print(char **str, char **str2)
{
	char ***result = (char *** )malloc(sizeof(char **));

	//Result is ***(pointer pointing to array of strings) -> **(array of strings) -> * (string)


	//FIX: Wont work //**result = (char * )malloc(sizeof(char *));
	*result = (char ** )malloc(sizeof(char *));
	//Working : //result[0] = (char ** )malloc(sizeof(char *));
	result[1] = (char ** )malloc(sizeof(char *));
	
	// FIX: WOnt work //*result = (char **) malloc(sizeof(char) * 10);
	**result = (char *) malloc(sizeof(char) * 10);
	//WOrkin: //result[0][0] = (char *) malloc(sizeof(char) * 10);
	result[0][1] = (char *) malloc(sizeof(char) * 10);
	result[0][2] = (char *) malloc(sizeof(char) * 10);
	result[0][3] = (char *) malloc(sizeof(char) * 10);
	result[0][4] = (char *) malloc(sizeof(char) * 10);
	result[0][5] = (char *) malloc(sizeof(char) * 10);
	
	strcpy(str[0], "Praveen V\0");
	strcpy(str[1], "Prem V\0");

	strcpy(result[0][0], str[0]);
	strcpy(result[0][1], str[1]);

	printf("pv: %s: \n", str[0]);

	return result;
}
#endif

int main()
{
	char ***result;

	//char **str;// here its kind a equivalent to char *argv[]
	char *str[2];// here its kind a equivalent to char *argv[]

	//str = (char **)malloc(sizeof(char *)*2);  // here 2 indicates 2 (char*)
	str[0]=(char *)malloc(sizeof(char)*10);   // here 10 indicates 10 (char)
	strcpy(str[0],"abcdefghij\0");   // 10 length character 
	
	str[0]=(char *)realloc(str[0], 2*sizeof(char)*10);   // <same as above>
	str[1] = str[0] + 11;
	strcpy(str[1],"xyzlmnopqr\0");   // 10 length character

	printf("%s\n",str[0]);    // to print the string in case of c++
	printf("%s\n",str[1]);    // to print the string in case of c++

	//result = string_print(&str);
	result = string_print(&str[0], &str[1]);
	printf("%s\n",result[0][0]);    // to print the string in case of c++
	printf("%s\n",result[0][1]);    // to print the string in case of c++
	//printf("%s\n",*result[1]);    // to print the string in case of c++
	printf("%s\n",str[0]);    // to print the string in case of c++
}
