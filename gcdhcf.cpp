// using euclidean algorithm 
#include<iostream>
using namespace std;
int main(){
    int n1 , n2;
    cout<<"Enter the no 1 ";
    cin>>n1;
    cout<<"Enter the no 2";
    cin>>n2;

    while(n1>0 && n2>0){
        if(n1 > n2) {
            n1 = n1%n2;
            }
            else{
                n2 = n2%n1;
            }
            if(n1==0) cout<<"The Greatest common divisor is"<<n2;
            else cout<<"The greatest common divisor is "<<n1;
}
return 0;
}