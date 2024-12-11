#include<iostream>
using namespace std;
int main(){
    int number;
    cout<<"enter the no.";
    cin>>number;
    int temp = number;
    bool flag;
  while(temp%2 == 0 && number%3 == 0 && number%5 ==0){
    flag = true;
    temp = temp/2;
  }
   while(temp%3 == 0 && number%2 == 0 && number%5 == 0){
    flag = true;
    temp = temp/3;
  }
   while(temp%5 == 0 && number%3 == 0 && number%2 == 0){
    flag = true;
    temp = temp/5;
  }
  if(temp>5){
    flag = false;
  }
  if(flag==true){
    cout<<"the given no."<<number<<"eon no";
  }
  else cout<<"it's not eon";



}
