/*Rad sa binarnim stablom- Finkcija search(int num) koja vraca true ako broj postoji u stablu i stampa nivo
na kom se nalazi*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}NODE;

NODE *create(int x){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getLevel(NODE* node, int num, int level)
{
    if (node == NULL)
        return -1;
 
    if (node->key == num)
        return level;
 
    int downlevel = getLevel(node->left, num, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevel(node->right, num, level + 1);
    return downlevel;
}
 
/* Returns level of given data value */
int search(NODE* node, int num)
{
    printf("Level %d of value %d\n",getLevel(node, num, 0), num);
}


int main(){


    NODE *root;
    root = create(2);
    root->left = create(1);
    root->right = create(7);
    root->right->left = create(8);
    root->right->right = create(6);
    root->left->left = create(11);

    search(root, 14);
    search(root, 11);

    return 0;
}