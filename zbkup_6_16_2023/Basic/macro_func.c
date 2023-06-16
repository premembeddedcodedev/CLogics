#include<stdio.h>

#define add(a,b) a+b

#define string(i) printf(#i "\t adding\n")

#define swap(a,b)\ ({int temp;\
		temp = a;\
		a = b;\
		b = temp;\
		printf("%d, %d", a, b);})

int main()
{
	printf("value: %d\n", add(10, 20));

	string(praveen);

	{ \
		int temp, a = 10, b = 20;\
                temp = a;\
                a = b;\
                b = temp;\
                printf("%d, %d\n", a, b);\
	}
	
	
	//swap(20, 30);

	return 0;
}
