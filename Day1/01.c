#include<stdio.h>
int main()
{
    int N, sum=0,i=1;

    printf("Enter the natural number N:");
    scanf("%d", &N);
    while(i<=N){
        sum=sum+i;
        i++;

    }
    printf("Sum of first %d natural numbers = %d\n",N,sum);
    return 0; 
}
   

    


    

    
