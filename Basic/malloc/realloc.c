#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr, i , n1, n2;
	int a[4] = {101,102,103,104};
	
	printf("Enter size: ");
	scanf("%d", &n1);

	ptr = (int*) malloc(n1 * sizeof(int));

	printf("Addresses of previously allocated memory:\n");
	for(i = 0; i < n1; ++i)
		printf("%pc\n",ptr + i);

	*ptr = a[0];

	printf("%d\n", ptr[0]);

	printf("\nEnter the new size: ");
	scanf("%d", &n2);

	// rellocating the memory
	ptr = realloc(ptr, n2 * sizeof(int));

	printf("Addresses of newly allocated memory:\n");
	for(i = 0; i < n2; ++i)
		printf("%pc\n", ptr + i);
	
	printf("%d\n", ptr[0]);

	free(ptr);

	return 0;
}
