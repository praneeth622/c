#include<stdio.h>

void print(int arr[], int size){
    //int b =k;
    for(int i = 0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int zero(int* arr,int size){
    int count =0;
    for(int i =0;i<size;i++){
        if(arr[i] == 0){
            count = count+1;
        }
    //printf("%d\t",count);
    }
    if(count == size){
        //printf("%d   ",count);
        return 0;
    }
    else if(count <size){
        //printf("%d   ",count);
        return 1;
    }
    else{
        //printf("%d   ",count);
        return 0;
    }
    
}
int operation(int* arr, int numsSize){
    int min_value = -1;  
    for (int i = 0; i < numsSize; i++) {
        if (arr[i] != 0 && (min_value == -1 || arr[i] < min_value)) {
            min_value = arr[i];
        }
    }
    return min_value;
}
int minimumOperations(int* arr,int numsSize){
    int k =1;
    int count =0;
    //int arr1[numsSize];
    while(k){
        
        int min = operation(arr,numsSize);
        for(int i =0;i<numsSize;i++){
            if(arr[i]>0){
                arr[i] = arr[i]-min;
            }
        }
        
        
        //print(arr, numsSize);
        k = zero(arr,numsSize);
        //printf("\n");
        //printf("%d",k);
        count ++;
    }
    return count;
}

int main() {
    int nums[] = {1,5,0,3,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int count;
    count = minimumOperations(nums,numsSize);
    printf("%d",count);

    return 0;
}