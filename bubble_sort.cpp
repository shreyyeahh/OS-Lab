#include<iostream>
using namespace std;
void bubble_sort(int n , int arr[]){
for(int i= n-1 ; i>=0; i--){
    int didswap = 0;
    
    for(int j = 0;j<=i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j]= temp;
            didswap = 1;
        }
        
        
    }
    if(didswap == 0){
        break;
    }
}
for(int i= 0; i<n;i++){
    cout<<arr[i]<<" ";
}

}
int main(){
    int n;
    int arr[10];
    cout<<"enter the no. of elements ";
    cin>>n;
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(n , arr);
    return 0;
    }

    
