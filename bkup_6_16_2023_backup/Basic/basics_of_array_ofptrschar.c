#include <stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
	char a[ROWS][COLS] = {"Praveen","Qualcomm"};
	char a_ptr[COLS];	
	char *ptr[COLS];

	//ptr = a_ptr;
#if 1
	ptr[0] = &a[0][0];
	ptr[0] = a[0];
	ptr[0] = a;
	ptr[0] = &a;
#endif
#if 1
	printf("\nOffset:\n");
	//printf("%d\n", *ptr[0]);
	//null: printf("%p %p\n", ptr[0], ptr[1]);
	
	printf(" &a[0][0]:%p, a[0]:%p, a:%p, &a:%p\n", &a[0][0], a[0], a, &a);
	printf(" &a[0][0]:%p, a[0]:%p, a:%p, &a:%p\n", &a[0][0]+1, a[0]+1, a+1, &a+1);

	printf("%c\n", *(*ptr+0));
	printf("%c\n", *(*ptr+1));
	printf("%c\n", *(*ptr+2)); //2 because limit of COLS are 3 only
	
	printf("%c\n", *(*ptr+3));
	printf("%c\n", *(*ptr+4));
	printf("%c\n", *(*ptr+5)); // can be written as below
	printf("%c\n", (*ptr+1)[4]);

#endif	
	return 0;
}
