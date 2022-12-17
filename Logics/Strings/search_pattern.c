#include <stdio.h>
#include <string.h>

void search_pattern(char *str, char *ptr)
{
	int stlength = strlen(str), ptlength = strlen(ptr);
	int offset = 0, pt_off=0, inc_pattern = 0;

	printf("offset : ");
	for(offset = 0; offset < stlength; offset++) {
		for(pt_off = 0; pt_off <= ptlength; pt_off++) {
			/* offset + ptoff is comparing exact offset with pattern*/
			if(str[offset + pt_off] != ptr[pt_off])
					break;
		}
		/*if the pattern fully matches then only inc_pattern increasess otherwise No*/
		if(pt_off == ptlength) {
			printf("\t%d, ", offset);
			inc_pattern++;
		}
	}

	printf("\n (%s) pattern found...%d times!", ptr, inc_pattern);
}	

int main()
{
	char str[50] = "This is the program i am waiting for the";
	char ptr[4] = "is";

	search_pattern(str, ptr);

	return 0;
}
