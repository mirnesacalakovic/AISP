#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create(int key){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(node *tree){
    if(tree){
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void print_postorder(node *tree){
    if(tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->data);
    }
}
void print_preorder(node *tree){
    if(tree){
        printf("%d ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
        
    }
}

void dellTree(node *tree){
    if(tree){
        dellTree(tree->left);
        dellTree(tree->right);
        free(tree);
    }
}


node *insert(node *node, int key){
    if(node == NULL) 
        return create(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else 
        node->right = insert(node->right, key);
    return node;
}

node *minValueNode(node *node){
    struct node *current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

node *deleteNode(node *root, int key){
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }else if(root->right == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

    }
    return root;
}

node *search(node *root, int key){
    if(root == NULL || root->data == key)
        return root;
    else if(key > root->data)
        return search(root->right, key);
    else 
        return search(root->left, key);
}



int main(){

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    struct node *root1 = create(1);
    root1->left	= create(2);
    root1->right = create(3);
    root1->left->left = create(4);

    printf("preorder\n");
    print_preorder(root1);

    printf("\npostorder\n");
    print_postorder(root);
    

    return 0;
}