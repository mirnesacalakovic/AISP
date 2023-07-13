#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}NODE;


NODE *newNode(int x){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print_inorder(NODE *tree){
    if(tree){
        print_inorder(tree->left);
        printf("%d ", tree->key);
        print_inorder(tree->right);
    }
}

//BST

NODE *insert(NODE *node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else    
        node->right = insert(node->right, key);
    return node;
}

NODE *insert(NODE *node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

NODE *insert(NODE *node, int x){
    if(node == NULL)
        return newNode(x);
    else if(x < node->key)
        node->left = insert(node->left, x);
    else 
        node->right = insert(node->right, x);
    return node;
}



NODE *insert(NODE *node, int key){
    if(node == NULL)    
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

NODE *insert(NODE *node, int key){
    if (node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

NODE *insert(NODE *node, int value){
    if(node == NULL)
        return newNode(value);
    if(value < node->key)
        node->left = insert(node->left, value);
    else 
        node->right = insert(node->right, value);
    return node;
}


NODE *search(NODE *root, int x){
    if(root == NULL || root->key == x)
        return root->key;
    else if(x < root->key)
        search(root->left, x);
    else 
        search(root->right, x);
}

NODE *search(NODE *root, int x){
    if(root == NULL || root->key == x)
        return root->key;
    else if(x < root->key)
        return search(root->left, x);
    return search(root->right, x); 
}

int findMin(NODE *root){
    NODE *current = root;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}


//Stampaj sadrzaj u listovima

void listovi(NODE *root){
    if(root!=NULL){
        listovi(root->left);
        if((root->left == NULL)&&(root->right == NULL))
            printf("%d ", root->key);
        listovi(root->right);
    }
}

void listovi(NODE *root){
    if(root!=NULL){
        listovi(root->left);
        if((root->left== NULL)&&(root->right)==NULL)
            printf("%d ", root->key);
        listovi(root->right);
    }
}


//zbir svih elemenata

int Suma(NODE *root){
    if(root == NULL)
        return 0;
    else{
        return root->key + Suma(root->left) + Suma(root->right);
    }
}

int Suma(NODE *root){
    if(root == NULL)
        return 0;
    else    
        return root->key + Suma(root->left) + Suma(root->right);
}

//Broj elemenata

int BrojElem(NODE *root){
    if(root == NULL)
        return 0;
    else
        return 1 + BrojElem(root->left) + BrojElem(root->right);
}


//da li se element nalazi u stablu
int Postoji(NODE *root, int a){
    if(root == NULL)
        return 0;
    else if(root->key == a)
        return root->key;
    else
        return Postoji(root->left, a) || Postoji(root->right, a);
}

int Postoji(NODE *root, int a){
    if(root == NULL)
        return 0;
    else if(root->key == a)
        return root->key;
    else
        return Postoji(root->left, a) || Postoji(root->right, a);
}

//postoji li i level na kome je

int levelFind(NODE *root, int value, int level){
    if(root == NULL)
        return -1;
    if(root->key == value)
        return level;

    int downlevel = levelFind(root->left, value, level+1);

    if(downlevel != 0)
        return downlevel;
    
    downlevel = levelFind(root->right, value, level +1);

    return downlevel;
}

int search(NODE* root, int value){
    printf("Level %d of value %d", levelFind(root, value, 0), value);
}



int levelFind(NODE *root, int value, int level){
    if(root == NULL)
        return -1;

    if(root->key == value)
        return 0;
    
    int downlevel = levelFind(root->left, value, level+1);

    if(downlevel != 0)
        return downlevel;
    
    downlevel = levelFind(root->right, value, level+1);

    return downlevel;

}

int search(NODE *root, int x){
    printf("Level %d of node %d", levelFind(root, x, 0), x);
}

//broj elemenata na n-tom nivou


int Nivo(NODE* root, int n){
    int brEl;
    if(root != NULL){
        if(n != 0)
            brEl = Nivo(root->left, n-1) + Nivo(root->right, n-1);
        else
            brEl = 1;
    }else 
        brEl = 0;
    
    return brEl;
}

int Nivo(NODE *root, int n){
    int brEl;
    if(root != NULL){
        if(n != 0)
            brEl = Nivo(root->left, n-1) + Nivo(root->right, n-1);
        else
            brEl = 1;
    }else
        brEl = 0;
    return brEl;
}


// zbir el na n tom niovu

int Sumaaaa(NODE *root, int n){
    int s=0;
    if(root != NULL){
        if(n != 0){
            int s = root->key + Sumaaaa(root->left, n-1) + Sumaaaa(root->right, n-1);
        }else
            s = root->key;
    }else
        s = 0;

    return s;
}




//Max dubina



