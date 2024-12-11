#include<iostream>
#include vector;
using namespace std;

void ms(<vector>int &arr , int low , int high){
if(low==high) return;
int mid = (low+high) / 2;
ms(arr , low , mid);
ms(arr , mid+1 , high);
merging_them(arr , low , mid , high);
}
void merging_them(<vector>int &arr , int low , int mid , int high){
    int left = low;
    int right = mid+1;
    <vector>int temp;
    while(left<=mid && right<= high){
        if(arr[left]<= arr[right]){
            temp.push_back(left);
            left++;
        }
        else {
            temp.push_back(right);
            right++;
        
    }
    }
    while(left<=mid){
        temp.push_back(left);
        left++;
    }
    while(right<=high){
        temp.push_back(right);
        right++;
    }
    for(int i = low ; i<high; i++){
        arr[i] = arr[temp];
    }
    for(int i = low ; i<high; i++){
        cout<<arr[i]<" ";
    }
}
int main(){
    <vector>int arr;
    cout<<"Enetr the array elements";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int n = sizeof(arr);
    int low = arr[0];
    int high = arr[n-1];
    int mid = (low+high) / 2; 
    ms(arr, low , high);   
}