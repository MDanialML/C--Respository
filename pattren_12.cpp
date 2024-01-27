#include <iostream>
using namespace std;

// int main(){
//     int row,num;
//     cout <<"Enter number of Rows : ";
//     cin >> num;
//     row = 1;
//     int count = 1;
//     while(row <= num){
//         char ch = 'A';
//         int col = 1;
//         while(col <= row){
//            char character = ch + row - 1;
//             cout <<character<<" ";
//             col ++;
//         }
//         row++;
//         cout << endl;
//     }
// }
// int main(){
//     int row,num;
//     cout <<"Enter number of Rows : ";
//     cin >> num;
//     row = 1;
//     int count = 1;
//     while(row <= num){
//         char ch = 'A';
//         int col = 1;
//         while(col <= row){
//            char character = ch + col - 1;
//             cout <<character<<" ";
//             col ++;
//         }
//         row++;
//         cout << endl;
//     }
// }
int main(){
    int row,num;
    cout <<"Enter number of Rows : ";
    cin >> num;
    row = 1;
    int count = 1;
    while(row <= num){
        char ch = 'A';
        int col = 1;
        while(col <= row){
           char character = ch + count - 1;
            cout <<character<<" ";
            col ++;
            count++;
        }
        row++;
        cout << endl;
    }
}