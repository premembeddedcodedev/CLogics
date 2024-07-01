#include<stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void print_list(Node *head)
{
	Node *temp = head;

	printf("List: \t");
	while(temp!=NULL) {
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node *create_node(int value)
{
	Node *new;

	new = (Node *) malloc(sizeof(Node));
	new->data = value;
	new->next = NULL;

	return new;
}

void delete_element(Node **head, int element)
{
	if(!(*head))
		return;

	Node *temp = *head, *prev = NULL;

	if(temp->data == element) { //first node
		*head = temp->next;	
		return;
	} 

	while(temp->next) {
		prev = temp;
		temp = temp->next;
		if(temp->data == element)
			goto found;
	}

	printf("Not found an element\n");

	return;

found:
	prev->next = temp->next;
	free(temp);
	temp = NULL;

	return;	
}

void create_list_front(Node **head, int array[], int bound)
{
	int i = 0;

	if(!(*head)) {
		Node *new = create_node(array[i]);
		*head = new;
		i++;
	}

	for(int j = i; j<bound; j++) {
		Node *new = create_node(array[j]);
		new->next = *head;
		*head = new;
	}
}

void create_list_last(Node **head, int array[], int bound)
{
	int i = 0;

	if(!(*head)) {
		Node *new = create_node(array[i]);
		*head = new;
		i++;
	}

	for(int j = i; j<bound; j++) {
		Node *new = create_node(array[j]);
		Node *temp = *head;
		Node *prev;

		while(temp != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = new;
	}
}

void menu()
{
	printf("\nmenu:\n");
	printf("1.create from front list\n");
	printf("2.create from last list \n");
	printf("3.delete element from anywhere:\n");
}

int main()
{
	int ch, bound, element;
	printf("how many elements required:\n");
	scanf("%d", &bound);
	int array[bound];
	Node *head = NULL;

	while(1) {
		menu();
		printf("enter the choice : \n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:

				printf("enter first: linked list values: \n");
				for(int i=0;i<bound;i++)
					scanf("%d", &array[i]);
				printf("inserting from first\n");
				create_list_front(&head, array, bound);
				print_list(head);
				break;
			case 2:
				printf("enter ilast: linked list values: \n");
				for(int i=0;i<bound;i++)
					scanf("%d", &array[i]);
				printf("inserting from last\n");
				Node *head = NULL;
				create_list_last(&head, array, bound);
				print_list(head);
				break;
			case 3:
				printf("enter the element to delete\n");
				scanf("%d", &element);
				delete_element(&head, element);
				print_list(head);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				break;	
		};
	}

	return 0;
}

