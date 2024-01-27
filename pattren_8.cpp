#include <iostream>
using namespace std;

int main(){
    int row,num;
    cout << "Enter number of rows : " << endl;
    cin >> num;
    row = 1;

    while(row <= num){
        int col = 1;
        while(col <= num){
            char ch = 'A' + row - 1;
            cout << " " << ch;
            // if (row == 1){
            //     cout << " A ";
            // }
            // if(row == 2){
            //     cout << " B ";
            // }
            // if (row == 3){
            //     cout << " C ";
            // }
            col ++;
        }
        cout << endl;
        row ++;
    }
    return 0;
}