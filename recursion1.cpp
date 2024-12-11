#include<iostream>
using namespace std;
void func1(int i , int n){
    if(i>n)
    return;
    else
    func1(i+1 , n);
    cout<<i;

}
int main(){
    int i = 1;
    int n;
    cout<<"enter the no";
    cin>>n;
    func1(i , n);
}