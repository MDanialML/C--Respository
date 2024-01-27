#include <iostream>
using namespace std;

int main(){
    int i,n;
    i = 1;
    cout <<"Enter number rows to print pattren : ";
    cin >> n;
    while(i <= n){
        int j = 1;
        while (j <= n){
            cout <<" "<<n-j+1<<" "; // here it will print digit from n to 1 in a single row
            j++;
        }
        cout << endl;
        i++;
    }
}