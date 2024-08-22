#include<stdio.h>
#include<stdlib.h>

// Inisilizing 

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * create(int val){

    struct node*root;
    root=malloc(sizeof(struct node));
    root->left= NULL;
    root->right= NULL;
    root->data = val;

    return root;
}

//Inorder
void Inorder(struct node * root){
    if(root == NULL){
        return ;
    }

    Inorder(root->left);
    printf(" %d",root->data);
    Inorder(root->right);
}

void Postorder(struct node*root){
    if(root==NULL){
        return ;
    }
    printf( " %d", root->data);
    Postorder(root->right);
    Postorder(root->left);

}

void preorder(struct node*root){
    if(root == NULL){
        return ;
    }

    preorder(root->left);
    preorder(root->right);
    printf(" %d",root->data);

}

//Insert

struct node*insert(struct node*root,int val){
    if(val == NULL){
        return create(val);
    }
    else if (val < root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
}
//Search

struct node*search(struct node*root,int find){
    if(root == NULL){
        return NULL;
    }
    else if(find >root->data){
        return search(root->right,find);
    }
    else if(find<root->data){
        return search(root->left,find);
    }
}
struct node* delete(struct node*root){
    
}

int main(){

    struct node *root=NULL;
    root=malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;

    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);


    Inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    Postorder(root);
}