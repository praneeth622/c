#include<stdio.h>
#include<stdlib.h>

int arr[100];
int size = 0;

void swap(int *a,int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;
}

void insert(int val){
    if(size == 0){
        arr[1] = val;
        size++;
    }
    else{
        arr[size+1] = val;
        size++;
        int i = size;
        while(i > 1){
            int parent = i / 2;

            if(arr[parent]<arr[i]){
                swap(&arr[parent],&arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
}
void print()
{
  for (int i = 1; i < size+1; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
    
    insert(50);
    insert(55);
    insert(53);
    insert(52);
    insert(54);
    print();
}