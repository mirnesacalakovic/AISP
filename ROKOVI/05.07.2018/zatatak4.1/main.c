/*Napisati program koji radi sa binarnim stablom pretrazivanja. Implementirati funkciju za izracunavanje zbira elemenata stabla. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct node *left, *right;
}NODE;

NODE *newNode(int item){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(NODE *root){
    if(root != NULL){
        inorder(root->left);   
        printf("%d ", root->key);
        inorder(root->right);
    }
}

NODE* insert(NODE *node, int key) {
    if(node==NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    if(key > node->key)
        node->right = insert(node->right, key);
    return node;
}

NODE *search(NODE* root, int key){
    if(root == NULL || root->key == key)
        return key;
    if(root->key < key)
        return search(root->right, key);
    if(root->key > key)
        return search(root->left, key);
}

int sumValue(NODE* root){
    if(root==NULL)
        return 0;
    return root->key + sumValue(root->left) + sumValue(root->right);
}

int main() {

    NODE *root = NULL;
    root = insert(root, 50);
    insert (root, 20);
    insert(root, 30);

    inorder(root);
    printf("Suma elemenata je: %d ", sumValue(root));


    return 0;
}