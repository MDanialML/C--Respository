#include <iostream>
using namespace std;

int main(){
    int row,num;
    cout << "Enter number of Rows : "<<endl;
    cin >> num;
    row = 1;
    int count = 1;
    while (row <= num){
        int col = 1;
        while (col <= num){
            char ch = 'A' + count - 1;
            cout << ch<<" ";
            count++;
            col++;
            
        }
        cout << endl;
        //count++;
        row++;

    }
    return 0;
}