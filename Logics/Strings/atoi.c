#include <stdio.h>
/* typecasting to char * because we are telling to read by char by char*/
#define is_valid_num_nochar(str) (*(char *)str >= 48 && *(char *)str <58)

void atoi_imp(char *str)
{
	int sign = 1, number = 0, offset = 0;
	char *temp = str;

	if(!temp)
		return;
	
	if(*temp == '-') {
		sign = -1;
		temp++;
	}

	while(is_valid_num_nochar(temp)) {
			number = (number * 10)  + (*temp - 48);

		temp++;
	}

	printf("\nNumber: %d\n", sign*number);

}

int main()
{
	char str[] = "-124";

	atoi_imp(str);

	return 0;
}
