#include<stdio.h>
#define MAX_STACK_SIZE 5

int top = -1;

void push()
{


}

void pop()
{



}


int main()
{
	int sb, temp;
	
	printf("enter the stack bound: \n");
	scanf("%d", &sb);

	int stack[MAX_STACK_SIZE];

	printf("fill the stack elements: \n");
	for(int i=0; i<sb, i++) {
		scanf("%d", &temp);
		push(stack, temp);
	}

	return 0;
}
