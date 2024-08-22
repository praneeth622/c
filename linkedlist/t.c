#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int val;
    
    struct node *next;
    
    struct node *prev;
};
struct node * head;
    
//print the value at gien index number

void get(int index){
    
    struct node *temp;
    
    temp = head;
    
    //traverse the temp pointer till index
    
    for(int i=0;i<=index;i++){
        
        temp=temp->next;
    }
    
    printf("%d",temp->val);
}

// addAtHead

void addAtHead(int val){
    
    struct node * newnode;
    
    newnode= malloc(sizeof(struct node));
    
    //Assign in values to new node
    
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// Add At Tail or Add at end 

void addAtTail(int val){
    
    struct node *temp,*newnode;
    temp =head;
    
    newnode= malloc(sizeof(struct node));
    
    //Assign in values to new node
    
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    while(temp->next != NULL){
        temp=temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;
}

// Add A Element at given index

void addAtIndex(int index,int val,int size){
    
    struct node *temp, *newnode;
    temp =head;
    //int size;
    
    newnode= malloc(sizeof(struct node));
    
    // Alloting the values to new node
    
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    //Traversing till index -1
    if(index < 0 && index+1>size){
        printf("Enter the valid");
    }
    else if(index == 1){
        addAtHead(val);
    }
    for(int i=0;i<=index-1;i++){
        
        temp = temp->next;
    }
    
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev=newnode;
}

// Main Function

int main(){
    
    int val,index,size;
    struct node *head;
    printf("Enter the size of list");
    scanf("%d",&size);
    
    get(index);
    addAtHead(val);
    addAtTail(val);
    addAtIndex(index, val,size);
}