#include <iostream>
using namespace std;

int main(){
    int row,num;
    cout << "Enter number of rows  : ";
    cin >> num;
    row = 1;
    while (row <= num){
        int col = 1;
        while(col <= row){
            cout << row - col + 1 << " ";
            col ++;
        }
        cout << endl;
        row ++;
    }
}