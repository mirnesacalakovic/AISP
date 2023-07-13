#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
}NODE;

NODE *create(int key){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print_preorder(NODE *root){
    if(root){
        printf("%d ", root->key);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(NODE *tree){
    if(tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ", tree->key);
    }
}



NODE *insert(NODE *node,int key){
    if(node == NULL)
        return create(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int main(){

    NODE *root1 = NULL, *root2 = NULL;

    root1 = create(1);
    root1->left = create(4);
    root1->right = create(7);
    root1->left->left = create(3);

    printf("Preorder\n");
    print_preorder(root1);

    root2 = insert(root2, 7);
    insert(root2,4);
    insert(root2, 2);
    insert(root2, 1);
    insert(root2, 11); 
    insert(root2, 24);

    printf("\nPostorder\n");
    print_postorder(root2);

}