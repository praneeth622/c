#include<stdio.h>
#include<stdlib.h>

// Intitalizing nodes

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

//Main Function

int main(){
    struct node *head =NULL;
    struct node *one =NULL;
    struct node *two =NULL;
    struct node *three = NULL;

    // Allocate the memory size

    struct node * head = malloc(sizeof(struct node));
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));

    // assign the values 

    one->data=1;
    two->data=2;
    three->data=3;

    //conecting the nodes

    head->prev=NULL;
    head->next=one->prev;
    
    one->next=two->prev;

    two->next=three->prev;

    three->next=NULL;

}