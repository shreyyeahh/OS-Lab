#include<stdio.h>
int main(){
    int i , n , tat[5] , bt[5] , wt[5] , atat;
    printf("Enter the no. of processes required");
    scanf("%d", &n);
    printf("Enter the Burst Time");
    for(i=0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the waiting time is ");
    wt[0] = 0;
    for(i=1;i<n;i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
        
    }
    for(i=0;i<n;i++)
    {
        printf("%d", wt[i]);

    }
    printf("the turn arount time of each process is ");
    for(i=0; i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
    for(i=0;i<n;i++)
    {
        printf("%d",tat[i]);
    }
    printf("the average turn around time is ");
    atat= 0;
    int tatat =0;
    for(i=0;i<n;i++)
    {
        tatat = (bt[i] + wt[i]) + tatat;
            }
            atat = tatat/n;
            printf("%d", tatat);

            

}