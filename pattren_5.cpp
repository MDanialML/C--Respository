#include <iostream>
using namespace std;

int main(){
    int row , n;
    cout << "Enter number of lines : " << endl;
    cin >> n;
    row = 1;
    while(row <= n){
        int col = 1;
        while ( col <= row){
            cout << " * ";
            col ++;
        }
        cout << endl;
        row ++;
    }

}