#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE;

NODE *newNode(int data){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int Zbir(NODE *root){
    int leftSum = 0;
    if(root == NULL)
        return 0;
    else { 
        leftSum += root->data + Zbir(root->left) + Zbir(root->right);
        return leftSum;
    }
}

int main(){

    NODE *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(8);
    root->left->left = newNode(6);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(4);

    int zbir = Zbir(root->left);
    printf("%d ", zbir);

    return 0;
}