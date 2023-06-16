#include <stdio.h>

int main()
{
	char *str[5] = {"prem", "praveen",  "Lattice", "Qualcomm",  "Moschip"};
	int  i = 0;
	char *ptr = "Praveen";
	//char ptr[] = "Praveen";
#if 1
	//while((*str)[i] != '\0') {	
	//while(*(*str+i) != '\0') {	
	while(*(str[2]+i) != '\0') {	
	//while(*(*(str+0)+i) != '\0') {	
	//while((str[0][i]) != '\0') {	
		printf("%c\t", str[2][i]);
		i++;
	}
#endif

#if 0
	while(*ptr != '\0') {
	//while(ptr[i] != '\0') {
		printf("%c\t", *ptr++);
		//printf("%c\t", ptr[i]);
		//*++ptr; // should not be ++*p
		//i++;
	}
#endif
	printf("\n");

	return 0;
}
