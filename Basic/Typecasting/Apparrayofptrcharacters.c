#include <stdio.h>
#include <string.h>

int main()
{
	int *A[5];
	int b[10] = {1,2,3,4,5,6,7,8,9,10};
	char c[] = {'Q', 'U', 'A', 'L', 'C', 'O', 'M', 'M', '\0'};
	int z;
	char d[] = "Qpraveen\0"; //XXX: Need to add '\0' when we specifically declare array with empty braces with combined string too 
	int L[10] = {1,2,3,4,5,6,7,8,9,10}; //see TODO of A[1] why its not printing
	char m[] = "ZAPTICpraveen\0"; //XXX: Need to add '\0' when we specifically declare array with empty braces with combined string too 
	char *e = "Zpraveen";
	int i;

	A[0] = (int *)b;
	printf("1.Integer array stored : \t");
	for(i=0; i<10; i++)
		printf("%d ", A[0][i]);

	A[1] = (int *)c;
	printf("\n2.characters with individual chars: \t");
	char *ptr = (char *) A[1];
	printf("%s\n", (char *)A[1]);
	//TODO: Need to see if we print 30 characters from A[1] why it is printing m[] chars may be consecutive elements in Stack
	//But if i declare integer array between even then its printing m elements 
	for(i=0; i<30; i++)
		printf("%c", ptr[i]);

	// XXX: CAUTION: below code wont work because if you increment A in the below it should print garbage
	// due to pointer increment will be 4 bytes every iteration. so you must take similar data type
	// for the pointer when you print back.
	// Like: when int* pointing to char *..take char* back from int* and print like above.
	/*for(i=0; i<20; i++)
		printf("%c", *((char *)(A+1)+i));*/


	A[2] = (int *)d;
	printf("\n3.character arrayi string: \t");
	printf("%s\n", (char *)A[2]);
	ptr = (char *)A[2];
	for(i=0; i<10; i++)
		printf("%c", ptr[i]);
		//Read XXX once... printf("%c", A[2][i]);
	
	A[3] = (int *)e;
	printf("\n4.Character pointer string: \t");
	printf("%ls\n", A[3]);
	ptr = (char *)A[3];
	for(i=0; i<strlen(e); i++)
		printf("%c", ptr[i]);
		//Read XXX one ....printf("%c", A[3][i]);

	char *p = "prem";
	printf("\n5.%s\n", p);
	for(i=0; i<strlen(p); i++)
		printf("%c", p[i]);
		
	printf("\n");

#if 0
	printf("Output Strings are: \n");
	for(i=0; i<5; i++)
		printf("%s\n", (char *)&A[i]);
	for(i=0; i<5; i++)
		printf("%s\n", &A[i]);
#endif	

	return 0;
}
