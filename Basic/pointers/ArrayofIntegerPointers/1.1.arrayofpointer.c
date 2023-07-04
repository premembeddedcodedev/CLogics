#include <stdio.h>

//void extract_ptr_to_arr(int **ptr) // wont workout
void extract_ptr_to_arr(int (*ptr)[])
{
	int i;

	for(i=0; i<10; i++) {
		(*ptr)[i] = i+100;
		//printf(" %d \t", (*ptr)[i]);
		printf(" %d \t", *((*ptr)+i));
	}

}

int main()
{
	int i=0,(*ptr)[10], a[10]={232,122,323,542,745,826,172,81,29,1230}, *temp[10];

	ptr = &a; //eventhough a and &a are same but without '&' compiler giving warning

	/*Different*/	
	printf("ptr Address : %p\t", ptr);
	printf("ptr Address : %p\n", &ptr);
	
	temp[0] = (int *)ptr; //without cast throwing some warning


	printf("aAddress : %p\t", a);
	printf("aAddress : %p\n", &a);

	for(i=0; i<10; i++) {
		printf(" %d \t", (*ptr)[i]);
		printf("Values: %d\n", *(temp[0]+i));
	}

	extract_ptr_to_arr(ptr);

	for(i=0; i<10; i++) {
		printf(" %d \t", (*ptr)[i]);
		printf("Values: %d\n", *(temp[0]+i));
	}

	return 0;
}
