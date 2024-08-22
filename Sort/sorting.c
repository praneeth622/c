#include<stdio.h>

int main (){
    int i,sum1 = 0,n,j;

    int arr[10] = {1,2,3,4,5,6,7,8,9};

    printf("enter the elements : ");
    scanf("%d",&n);

    i = 0;
    j =10-1 ;

    while(i<j){
        if (arr[i]+arr[j] == n){
        printf("found");
        break;
    }
    else if (arr[i]+arr[j] > n){
        j--;
        break;
    }
    else if(arr[i]+arr[j] == n){
        i++;
    }
    else{
        printf("not found");
        break;
    }
    }
}