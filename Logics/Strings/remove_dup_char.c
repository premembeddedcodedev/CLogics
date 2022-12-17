#include <stdio.h>

#define CHAR_UNUSED_FLAG 0
#define CHAR_ALREADY_USED 1;

void find_dup(char *str)
{
	unsigned int stringindex=0, resultindex=0 ;
	char var;
	char char_table[256] = {0};
	
	while(*(str+stringindex)) {
		if(char_table[*(str+stringindex)] == CHAR_UNUSED_FLAG) {
			
			char_table[*(str+stringindex)] = CHAR_ALREADY_USED;

			/*skippping the stringindex which is duplicated here to print string*/
			*(str+resultindex) = *(str+stringindex);
		
			resultindex++;
		}
		stringindex++;
	}
	/*Taking resultindex because duplicates are moved lead to empty with stringindex*/
	*(str+resultindex) = '\0';

	printf("\nstr is %s\n", str);
}

int main()
{
	char str[10] = "PREVREN";

	find_dup(str);

	return 0;
}
