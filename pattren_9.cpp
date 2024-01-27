#include <iostream>
using namespace std;

int main(){
    int row,num;
    cout <<"Enter number of rows :";
    cin >> num;
    row = 1;
    while(row <= num){
        int col = 1;
        //char ch = 'A';
        while (col <= num){
            char ch = 'A' + col - 1;
            cout <<ch <<" ";
            col++;

        }
        cout << endl;
        row ++;
    }
    return 0;
}