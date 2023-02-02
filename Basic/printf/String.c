#include <stdio.h>

void func(char ***ptr)
{
	printf("In Function: \n");
	printf("%s\n", ptr);
	printf("%c\n", *ptr+1);
	printf("%s\n", ptr+1);
	printf("%s\n", ptr+2);
	//printf("%s\n", *ptr[0]);
//	printf("%c\t", *(*(ptr+0)+0));
//	printf("%c\t", *(*(ptr+0)+1));
//	printf("%c\t", *(*(ptr+0)+2));
//	printf("%c\t", *(*(ptr+0)+3));

}

int main()
{
	char ptr[5][4] = {"Prem\0", "Qsfn\0", "Rtgo\0", "Suhp\0", "Tvi\0"};
	//char *ptr[5] = {"Prem\0", "Qsfn\0", "Rtgo\0", "Suhp\0", "Tvi\0"};
#if 1
	printf("%c\t", *(*(ptr+0)+0));
	printf("%c\t", *(*(ptr+0)+1));
	printf("%c\t", *(*(ptr+0)+2));
	printf("%c\t", *(*(ptr+0)+3));

	printf("\n");

	printf("%c\t", *(*(ptr+1)+0));
	printf("%c\t", *(*(ptr+1)+1));
	printf("%c\t", *(*(ptr+1)+2));
	printf("%c\t", *(*(ptr+1)+3));
	
	printf("\n");

	printf("%c\t", *(*(ptr+2)+0));
	printf("%c\t", *(*(ptr+2)+1));
	printf("%c\t", *(*(ptr+2)+2));
	printf("%c\t", *(*(ptr+2)+3));
#endif
	func(&ptr);

	return 0;
}
