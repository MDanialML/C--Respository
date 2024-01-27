#include <iostream>
using namespace std;

int main(){

    /*int n ;
    cout <<"Input any number";
    cin >>n;
    if (n > 0){
        cout << "Number is positive ";
    } 
    else{
        cout << "Number is negative";
    } 
    
   int a ,b,result;
   cout << "Enter the value of a and b : " <<endl;
   a = cin.get();
   b = cin.get();
   result = a + b;
   cout << "Sum of two integers : "<<result<<endl;
   
  int i,n,sum;
  i = 1;
  sum = 0;
  cout << "Enter end of range : "<<endl;
  cin >> n;
  while(i<=n){
    sum = sum + i;
    i++;
  }
  cout << "Total Sum : "<<sum<<endl;

  */
 //Sum of n even numbers
    // int strt,end,n,sum;
    // sum = 2
    // cout <<"Enter Start and End value to get the sum of all even number Occurence : "<<endl;
    // cin >>strt>>end;
    // while (strt <= end){
    //     if (strt%2 != 0){
    //         for (int i =strt;i<=end;i++){
    //             //
    //         }

    //     }
    // }
    int n,i;
    i = 2;
    cout<<"Enter number : ";
    cin >> n;
    while(i < n){
        if (n % i != 0 ){
            cout << "Number is prime for : "<< i<<endl;
        }
        else{
            cout <<"Number is not prime for : "<<i<<endl;
        }
        i++;
    }

}