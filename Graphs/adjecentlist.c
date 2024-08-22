#include<stdio.h>
#include<stdlib.h>

// To represent a node in the adjacency list
struct node {
    int data;
    struct node* next;
};

// Create adjacency list
void createGraph(struct node* adj[], int no_vertices) {
    //now we are creating loop for add ing sub vertices(adj vertices) for total no of vertices 
    int k, value;
    struct node* newnode;
    struct node* temp;
    
    for (int i = 0; i < no_vertices; i++) {
        printf("No. of sub vertices for %d: ", i);
        scanf("%d", &k);
        
        // Now we will scan the sub vertices
        for (int j = 1; j <= k; j++) {//No need of j=0 as subvertex is taken in linkedlist 
            newnode = malloc(sizeof(struct node));
            printf("Enter the %dst node linked with %d: ", j, i);
            scanf("%d", &value);
            newnode->data = value;
            newnode->next = NULL;
            
            // Link the new node to adjacency list
            if (adj[i] == NULL) {
                adj[i] = newnode;
            } else {
                // Link it with the last node
                temp = adj[i];
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
    }
}

// Print the graph
void printGraph(struct node* adj[], int no_vertices) {
    struct node* temp;
    for (int i = 0; i < no_vertices; i++) {
        temp = adj[i];
        printf("Vertices linked with %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int no_vertices;
    printf("No. of vertices required: ");
    scanf("%d", &no_vertices);

    struct node* adj[no_vertices]; // Array to store vertices

    for (int i = 0; i < no_vertices; i++) {
        adj[i] = NULL;
    }
    
    createGraph(adj, no_vertices);
    printGraph(adj, no_vertices);

    return 0;
}
