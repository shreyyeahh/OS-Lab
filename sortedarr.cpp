#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check_sorted(int n , int arr[]){
    for(int i = 1; i<=n;i++){
        if(arr[i] < arr[i-1]){
            return false;

        }
        return true;
        
        
        
    }

}
int main(){
    int arr[] = {};
    int n ;
    cout<<"Enter the elements you want in array";
    cin>>n;
    cout<<"enter the elements of array";
    for(int i = 0;i<=n;i++){
        cin>>arr[i];
        
    }
    bool ans = check_sorted(n , arr);
    if(ans){
        cout<<"true";

    }
    else cout<<"false";
    


}