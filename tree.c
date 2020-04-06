#include<stdio.h>
#include<conio.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
	return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
void pre(node *temp)
{
  if(temp!=NULL)
  {
    printf("  %d",temp->data);
    pre(temp->left);
    pre(temp->right);
  }
}
void in(node *temp)
{
  if(temp!=NULL)
  {
    in(t->left);
    printf("  %d",temp->data);
    in(temp->right);
  }
}
void post(node *temp)
{
  if(temp!=NULL)
  {
    post(temp->left);
    post(temp->right);
    printf("  %d",temp->data);
  }
}
void main()
{
  node *root;
  root=create();
  printf("\nThe preorder traversal of tree is: ");
  pre(root);
  printf("\nThe inorder traversal of tree is: ");
  in(root);
  printf("\nThe postorder traversal of tree is: ");
  post(root);
  
}