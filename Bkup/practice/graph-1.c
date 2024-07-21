#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node {
	int val;
	struct node *next;
};

struct graph {
	struct node *list[MAX];
};

void alloc_node(struct graph *root, int src, int dst)
{
	struct node *new = (struct node *) malloc (sizeof(struct node));
        if(!new)
                return;

        new->val = dst;
        new->next = NULL;

        if(!root->list[src])
                root->list[src] = new;
	else {
		struct node *temp = root->list[src];
		while(temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void print_graph(struct graph *root, int vertices)
{
	if(!root)
		return;

	int i = 0;

	while(i++ < vertices) {
		struct node *temp = root->list[i];
		printf("%d: ", i);
		while(temp) {
			printf("%d -> ", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	struct graph *root = NULL;

	root = (struct graph *) malloc(sizeof(struct graph));
	if(!root)
		return -1;

	int vertices, links;
	printf("vertices : ");
	scanf("%d", &vertices);

	printf("links : ");
	scanf("%d", &links);
	
	int src, dst;

	for(int i = 0; i<links; i++) {
		scanf("%d %d", &src, &dst);
		alloc_node(root, src, dst);
	}

	print_graph(root, vertices);

	return 0;
}
