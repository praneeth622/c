#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node*link;
};

void addtoend(struct node*head ,int data){
  struct node*ptr, *temp;
  ptr = head;
  temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link =NULL;
  //sending ptr to last node
  while(ptr->link !=NULL){
    ptr = ptr->link;
  }
  ptr->link =temp;
}

//printing linked list
void printlist(struct node*head){
    struct node*ptr;
    ptr =head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }

}
int main(){
  //Creating First node

  struct node*head =NULL;
  head = malloc(sizeof(struct node));
  head->data = 64;
  head->link = NULL;

  //Creating Secound node

  struct node* current = NULL;
  current = malloc(sizeof(struct node));
  current->data = 54;
  current->link =NULL;

  //Linking head node to current node 

  head->link = current;

  // Linking 3rd node using function
  addtoend(head,65);
  
  printlist(head);
}