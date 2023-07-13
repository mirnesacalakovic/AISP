#include<stdlib.h>
#include<stdio.h>


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

/* newNode() allocates a new node with the given data and NULL left and
right pointers. */


struct node* newNode(int data)
{
// Allocate memory for new node
struct node* node = (struct node*)malloc(sizeof(struct node));

// Assign data to this node
node->data = data;

// Initialize left and right children as NULL
node->left = NULL;
node->right = NULL;
return(node);
}




void print_preorder(struct node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}




void print_inorder(struct node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(struct node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(struct node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }}





int main()
{
/*create root*/
struct node *root = newNode(1);
/* following is the tree after above statement

     1
	/ \
NULL  NULL
*/


root->left	 = newNode(2);
root->right	 = newNode(3);
/* 2 and 3 become left and right children of 1
	   1
	  / \
	2	 3
	/ \ / \
	NULL NULL NULL NULL
*/


root->left->left = newNode(4);
/* 4 becomes left child of 2
	    1
	 /	   \
    2	     3
   / \	   /   \
  4  NULL NULL NULL
 /     \
NULL  NULL
*/
printf("preorder\n");
print_preorder(root);
printf("inorder\n");
print_inorder(root);
printf("postorder\n");
print_postorder(root);
printf("deletion");
deltree(root->left);
getchar();
return 0;
}