#include <iostream>
using namespace std;

int main(){
    int row , num;
    cout << "Enter number of rows : " << endl;
    cin >> num;
    row = 1;
   
    while (row <= num){
        //int value = row; i should solve this in order to become a champion
        int col = 1;
        while(col <= row){
            //cout << " " << value;
            //value ++;
            col ++;
        }
        
        cout << endl;
        row ++;
    }
}