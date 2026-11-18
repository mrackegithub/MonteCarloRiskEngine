#include "def.h"

int add_node(Node **root, Stock data_stock)
{
    // adds nodes to the bst, sorts by name
    Node **cur = root;
    while(*cur!=NULL){
        int cmp = strcmp(data_stock.ticker,(*cur)->data.ticker);
        if(cmp<0){
            cur=&(*cur)->left;
        } else if(cmp>0){
            cur=&(*cur)->right;
        } else {
            (*cur)->data=data_stock;
            return 1;
        }
    }
    *cur = malloc(sizeof(Node));
    if(*cur==NULL){
        printf("gle ko nam to ostade bez memorije :(\n");
        return 0;
    }
    (*cur)->data=data_stock;
    (*cur)->left=NULL;
    (*cur)->right=NULL;
    return 1;
}

void print_tree(Node *root){//in order
    if(root==NULL){
        return;
    }
    print_tree(root->left);
    printf("%s\n",root->data.ticker);
    print_tree(root->right);
}

void free_tree(Node *root){//post order
    if(root==NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}