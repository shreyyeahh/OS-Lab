#include <iostream>
using namespace std;

int main(){
     int arr[6];
      int n = 6;
      int lar = 0;
     cout<<"Enter the elememts of the array";
     for (int i = 0 ; i<n ; i++){
        cin>>arr[i];
     }
     for(int i =0; i<n ; i++){
        if(arr[i] > lar){
            lar = arr[i];
        }
     }
     cout<<lar;
     return 0;

}