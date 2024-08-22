#include<stdio.h>
#define MAX_INSTANCES 6
#define MAX_DIGITS 48
#define MAX_DIGITS_PER_INSTANCE 8 
int main()
{
    int instances[MAX_INSTANCES][MAX_DIGITS_PER_INSTANCE];
    int sum[MAX_INSTANCES]={0};
    int instance=0;
    int digits=0;
    int input;
    printf("welcome to number marathon!\n");
    printf("enter the digits");
    while(1)
    {
        printf("enter the digits(0-9)");
        scanf("%d",&input);
        if(input==0)
        {
            printf("course ended.\n");
            break;
        }
        if(input>=1 && input<=8)
        {
            if(digits<MAX_DIGITS)
            {
                instances[instance][digits%MAX_DIGITS_PER_INSTANCE]=input;
            }
        }
    }
}