#include<stdio.h>
#include<stdlib.h>
//Defining procress
typedef struct process{
    int pid;
    int at;
    int bt;
    int ft;
    int tat;
    int wt;
    int rt;
}process;

//node Structure
typedef struct node{
    process Process;
    struct node* next;
}node;

// This function create a new node
node *createnode(process p){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->Process=p;
    newnode->next=NULL;
    return newnode;
}

//To enqueue to the exsisting queue
void enqueue(node **front,node **rear,process p){
    node *newnode=createnode(p);
    if(*front==NULL){
        *front=newnode;
        *rear=newnode;
        return;
    }
    (*rear)->next=newnode;
    *rear=newnode;
}

//removing the node from the queue
process dequeue(node **front,node **rear){
    if(*front==NULL){
        process EmptyProcess;
        EmptyProcess.pid=-1;
        return EmptyProcess;
    }
    node *temp=*front;
    process p=temp->Process;
    *front=(*front)->next;
    if(*front==NULL){
        *rear=NULL;
    }
    free(temp);
    return p;
}


void fcfs(process p[],int n){
    node *front=NULL;
    node *rear=NULL;

    for(int i=0;i<n;i++){
        enqueue(&front,&rear,p[i]);
    }

    int current_time=0;
    int process_completed=0;

    while(process_completed<n){
        process current_process=dequeue(&front,&rear);
        if(current_process.pid==-1){
            current_time++;
            continue;
        }
            current_process.ft=current_time+current_process.bt;
            current_process.tat=current_process.ft-current_process.at;
            current_process.wt=current_process.tat-current_process.bt;
            current_process.rt=current_time-current_process.at;

            current_time+=current_process.bt;
            p[current_process.pid-1]=current_process;
            process_completed++;
    }
}

int main(){
    int n;
    printf("Enter Total No of Process: \n");
    scanf("%d",&n);

    process p[n];
    for(int i=0;i<n;i++){
        printf("\nProcess ID: ");
        scanf("%d",&p[i].pid);
        printf("\nArrival Time:");
        scanf("%d",&p[i].at);
        printf("\nBurst Time:");
        scanf("%d",&p[i].bt);
    }
    fcfs(p,n);
    
    //printing the fcfs
    int t_wt=0;
    int t_tat=0;

    printf("FCFS\n");
    
    printf("P_id \tAT\tBT\tFT\tTAT\tWT\tRT\n");
    
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt,p[i].rt);
        t_wt+=p[i].wt;
        t_tat+=p[i].tat;
    }
    
    printf("Average Waitng time is :%.2f\n",(double)t_wt/n);
    
    printf("Total Turn Around time is :%.2f\n",(double)t_tat/n);
    
    return 0;
}
