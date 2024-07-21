#include<stdio.h>
#include <stdlib.h>

typedef struct d_tree
{
	int data;
	struct d_tree *left;
	struct d_tree *right;
}tree_list;

tree_list *alloc_nodes()
{
	int value;
	tree_list *root = (tree_list *)malloc(sizeof(tree_list));
	if(!root)
		return NULL;
	
	printf("Enter the value to assign : ");
	scanf("%d", &value);

	if(value == 0)
		return NULL;

	root->data = value;

	root->left = alloc_nodes();
	root->right = alloc_nodes();

	return root;
}

void pre_order(tree_list *root)
{
	if(!root)
		return;
	printf(" %d,", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

void in_order(tree_list *root)
{
	if(!root)
		return;
	in_order(root->left);
	printf(" %d,", root->data);
	in_order(root->right);
}

void post_order(tree_list *root)
{
	if(!root)
		return;
	post_order(root->left);
	post_order(root->right);
	printf(" %d,", root->data);
}

int main()
{
	int value;
	tree_list *root;

	root = alloc_nodes();
	printf("\npre-order : \n");
	pre_order(root);
	printf("\nin-order : \n");
	in_order(root);
	printf("\npost-order : \n");
	post_order(root);
	printf("\n");

	return 0;
}
