#include<iostream>
using namespace std;

int main(){
    int i,n;
    i = 1;
    cout<<"Enter number of rows wants to print : "<<endl;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        while(j <= n){
            //cout <<" * ";
            cout<<" "<<i<<" ";
            j ++;
        }
        cout<<endl;
        i++;
    }
    
}