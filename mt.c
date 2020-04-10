#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
void create(struct node *temp)
{
    if(temp->data!=-1)
    {
        struct node *lt=(struct node *)malloc(sizeof(struct node));
		if (lt)
		{
            temp->left=lt;
            printf("Enter data to  left of \"%d\" :",temp->data);
            scanf("%d",&temp->left->data);
            create(temp->left);
        }
        else
            printf("Something went wrong while creating left node");

        struct node *rt=(struct node *)malloc(sizeof(struct node));
		if (rt)
		{
            temp->right=rt;
            printf("Enter data to right of \"%d\" :",temp->data);
            scanf("%d",&temp->right->data);
            create(temp->right);
        }
        else
            printf("Something went wrong while creating right node");
    }
}
void pre(struct node *temp)
{
    if(temp->data!=-1)
    {
        printf("  %d",temp->data);
        pre(temp->left);
        pre(temp->right);
    }
}
void in(struct node *temp)
{
    if(temp->data!=-1)
    {
        in(temp->left);
        printf("  %d",temp->data);
        in(temp->right);
    }
}
void post(struct node *temp)
{
    if(temp->data!=-1)
    {
        post(temp->left);
        post(temp->right);
        printf("  %d",temp->data);
    }
}
void main()
{
    root=(struct node *)malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("Memory not allocated");
	}
	else
	{
        printf("\n-1 equals null");
        printf("\nEnter rooot data:");
        scanf("%d",&root->data);
        create(root);
        printf("\nThe preorder traversal of tree is:  ");
        pre(root);
        printf("\nThe inorder traversal of tree is:   ");
        in(root);
        printf("\nThe postorder traversal of tree is: ");
        post(root);
    }  
}