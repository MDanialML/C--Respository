#include <iostream>
using namespace std;

int main(){
    int i,n,op;
    cout << "Enter number of lines" <<endl;
    cin >> n;
    i = 1;
    op = 1;
    while (i <= n){
        int j = 1;
        while(j <= n){
            cout << " " << op;
            op++;
            j++;
        }
        cout << endl;
        i++;
    }

}