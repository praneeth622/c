#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int pid;
    int at;
    int bt;
    int ft;
    int tat;
    int wt;
    int rt;
    struct node *next;
} Node;

typedef struct minheap {
    Node **arr;
    int size;
    int cap;
} Minheap;

Node* createnode(int p, int a, int b) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->pid = p;
    newn->at = a;
    newn->bt = b;
    newn->ft = 0;
    newn->tat = 0;
    newn->wt = 0;
    newn->rt = 0;
    newn->next = NULL;
    return newn;
}

Minheap* createMinh(int capacity) {
    Minheap* temp = (Minheap*)malloc(sizeof(Minheap));
    temp->size = 0;
    temp->cap = capacity;
    temp->arr = (Node**)malloc(capacity * sizeof(Node*));
    return temp;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(Minheap *heap, int id) {
    int s = id;
    int l = 2 * id + 1;
    int r = 2 * id + 2;
    
    if (l < heap->size && heap->arr[l]->bt < heap->arr[s]->bt) {
        s = l;
    }
    if (r < heap->size && heap->arr[r]->bt < heap->arr[s]->bt) {
        s = r;
    }
    if (s != id) {
        swap(&heap->arr[s], &heap->arr[id]);
        minheapify(heap, s);
    }
}

void insertminh(Minheap *heap, Node *temp) {
    if (heap->size == heap->cap) {
        printf("Heap capacity exceeded\n");
        return;
    }
    int id = heap->size++;
    heap->arr[id] = temp;
    while (id != 0 && heap->arr[(id - 1) / 2]->bt > heap->arr[id]->bt) {
        swap(&heap->arr[id], &heap->arr[(id - 1) / 2]);
        id = (id - 1) / 2;
    }
}

Node* extractminh(Minheap *heap) {
    if (heap->size == 0) {
        return NULL;
    }
    Node* root = heap->arr[0];
    Node* lastnode = heap->arr[--heap->size];
    heap->arr[0] = lastnode;
    minheapify(heap, 0);
    return root;
}

void SJF(Node* process[], int n) {
    int c_time = 0;
    Minheap *heap = createMinh(n);
    int swt = 0, stat = 0, i = 0;
    
    printf("P_id\tAT\tBT\tFT\tTAT\tWT\tRT\n");

    while (i < n || heap->size > 0) {
        
        while (i < n && process[i]->at <= c_time) {
            insertminh(heap, process[i]);
            i++;
        }

        if (heap->size == 0) {
            c_time = process[i]->at;
            continue;
        }

        Node *p = extractminh(heap);
        c_time += p->bt;
        p->ft = c_time;
        p->tat = p->ft - p->at;
        p->wt = p->tat - p->bt;
        p->rt = 0;
        swt += p->wt;
        stat += p->tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pid, p->at, p->bt, p->ft, p->tat, p->wt, p->rt);
        free(p);
    }

    free(heap->arr);
    free(heap);
    printf("Avg Waiting Time is: %.2f\n", (float)swt / n);
    printf("Avg Turnaround Time is: %.2f\n", (float)stat / n);
}

int main() {
    printf("Enter the Number of processes: ");
    int n;
    scanf("%d", &n);
    
    int PID[n], AT[n], BT[n];
    
    printf("Enter the Process IDs array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &PID[i]);
    }
    
    printf("Enter the Arrival time (AT) array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
    }
    
    printf("Enter the Burst time (BT) array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
    }
    
    Node *p[n];
    
    for (int i = 0; i < n; i++) {
        p[i] = createnode(PID[i], AT[i], BT[i]);
    }
    
    SJF(p, n);
    
    return 0;
}