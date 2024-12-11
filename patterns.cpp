#include<iostream>
using namespace std;

    void Starprint1(int n){
      for(int i=0; i<n;i++){
         for (int j = 0; j < (n - i - 1); j++) {
        cout << " ";
      }
        for (int j = 0; j < (2*i +1); j++) {
        cout << "*";
      }
      for (int j = 0; j < (n - i - 1); j++) {
        cout << " ";
      }
        cout<<endl;
    }
    }
    void Starprint2(int n){
        for(int i=0;i<n;i++){

        for(int j =0;j<i;j++){
         cout<<" ";   
        }
        for(int j=0; j<(2*n -(2*i+1)); j++){
            cout<<"*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
int main(){

int n;
cout<<"enter the no.";
cin>>n;
Starprint1(n);
Starprint2(n);

}