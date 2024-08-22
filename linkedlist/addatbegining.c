#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};

void addtobegin(struct node**head){
    struct node*temp;
    //ptr = head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data =67;
    //temp->link=NULL;

    temp->link=*head;
    *head = temp;

}

void printlist(struct node *head){
    struct node*ptr;
    ptr =head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr= ptr->link;
    }
}

int main(){
    //creating first node;
    struct node*head=NULL;
    head = malloc(sizeof(struct node));
    head->data= 65;
    head->link=NULL;

    //Creating secound node 

    struct node*current = NULL;
    current = malloc(sizeof(struct node));
    current->data = 66;
    current->link=NULL;
    head->link = current;

    addtobegin(&head);
    printlist(head);
}