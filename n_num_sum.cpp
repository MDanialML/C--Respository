#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int num;
    cout<<"Enter number for Sum     ";
    cin>>num;
    for (int i = 1;i<= num;i++){
        sum = sum + i;}
    cout<<("sum is equal to = ",sum);
    return 0;
}