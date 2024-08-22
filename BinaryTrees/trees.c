#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node *right;

};
// Traversal of Binary Trees

//Preorder

void preorder(struct node * root){
    //root,left,right

    if(root == NULL){
        return;
    }
    //Root
    printf("%d ",root->data);

    //Left (We are using recurtion to slove this)
    preorder(root->left);

    //Right (Again we are using recurtion for this)
    preorder(root->right);
}

//Inorder
void inorder(struct node*root){
    //Left,Root,Right

    if(root==NULL){
        return;
    }
    //Left
    inorder(root->left);

    //Root
    printf("%d ",root->data);

    //Right
    preorder(root->right);
}

//postorder
void postorder(struct node*root){
    //Left,Right,Root
    if(root==NULL){
        return;
    }

    //Left
    postorder(root->left);

    //Right
    postorder(root->right);

    //Root
    printf("%d ",root->data);
}

//Creation of node
struct node* create(int val){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->left =NULL;
    newnode->right=NULL;
    newnode->data= val;

    return newnode;
}


int main(){
    struct node* root;
    root = malloc(sizeof(struct node));
    root->left = create(2);
    root->right = create(3);
    root->data= 1;
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}