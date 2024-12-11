#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

// Function to calculate the sum of divisors for a given number
//int sumOfDivisors(int n) {
  //  int result = 0;
    //for (int i = 1; i <= n; i++) {
      //  if (n % i == 0) {
        //    result += i;
        //}
    //}
    //return result;
//}



// Main function
//int main() {
//	cout<<"enter the no";
 //   int n;
	//cin>>n;
    //cout << sumOfDivisors(n) << endl; // Output: 21
    //return 0;
//}
int main(){
    int n;
    cout<<"enter the no";
    cin>>n;
    vector<int> ls;
    for(int i =1; i<= sqrt(n); i++){
        if(n%i==0){

        
        ls.push_back(i);
        
        if(n/i != i) {
            ls.push_back(n/i);
        }
        }
    }
        sort(ls.begin(), ls.end());
        for( auto it : ls){
            cout<<it<<" ";
        }
        
    }

