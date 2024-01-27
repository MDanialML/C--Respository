#include <iostream>
using namespace std;

int main(){
    int row,num;
    cout << "Enter number of Rows : ";
    cin >> num;
    row = 1;
    // char ch = 'A';
    while(row <= num){
        int col = 1;
        //ch = ch + row - 1;
        while(col <= num){
            // int formula = row + col -1;
            char ch = 'A' + row + col -1;
            // char ch = 'A' + formula;
            //char ch_2 = ch;
            //ch_2 = ch_2 + col - 1;
            cout << ch <<" ";
            col ++;
        }
        row++;
        cout << endl;
    }
    return 0;
}