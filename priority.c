#include<stdio.h>
int main(){
    int n ;
    printf("Enter the no. of process");
    scanf("%d" , &n);
    int burst[n], priorityno[n] , index[n];

    for(int i = 0; i<n; i++){
        printf("Enter the burst time and the priority no . for the process");
        scanf("%d %d" , &burst[i] , &priorityno[i]);
        index[i] = i + 1;
    }
    for(int i=0; i<n; i++){
        int temp = priorityno[i];
        int m = i;
        for(int j = i; j<n ; j++){
            if(priorityno[j] > temp){
                
            }
        }
    }
    

}