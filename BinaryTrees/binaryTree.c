#include<stdio.h>
#include<stdlib.h>

//Node initialization

struct node{
    int data;
    struct node*left;
    struct node*right;
};

//Node Creation

struct node*create(struct node*root,int val){

    struct node*newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left= NULL;
    newnode->right = NULL;

    return newnode;
}

//count Number of nodes in tree

int count(struct node*root){
    //we should use int as we are returning int count
    //to count we use recusive funtions
    //For most cases of binary try we use recursive functions

    if(root==NULL){
        return 0;
    }

    int nodes;
    nodes = (1+count(root->left)+count(root->right));
    return nodes;
}

//Checking tree is complete binary or not

int CompleteBTree(struct node*root){

    if(root == NULL){
        return 1;
    }

    if(((root->left !=NULL)&&(root->left->data >= root->data))||((root->right !=NULL)&&(root->right->data>=root->data))){
        return 0;
    }
    
    return (CompleteBTree(root->left)&&CompleteBTree(root->right));
    
}

//Full Tree
int FullTree(struct node*root){
    //node has node has either two or no children
    if(root == NULL){
        return 1;//null = 0 is full tree
    }

    if((root->left==NULL)&&(root->right==NULL)){
        return 1;
    }

    if((root->left)&&(root->right)){
        //if both nodes exits then it will return true and return down function
        return(FullTree(root->left)&&FullTree(root->right));
    }
    else{
        return 0;
    }
}

int main(){
    struct node*root;
    root=malloc(sizeof(struct node));
    root->right=create(root,12);
    root->right->left=create(root,11);
    root->left=create(root,10);
    root->left->left=create(root,8);
    root->left->right=create(root,19);

    printf("No of nodes =%d\n",count(root));

    if (CompleteBTree(root))
        printf("The given tree is a binary tree.\n");
    else
        printf("The given tree is not a binary tree.\n");

    if (FullTree(root))
        printf("The given tree is a binary tree.\n");
    else
        printf("The given tree is not a binary tree.\n");
    
}