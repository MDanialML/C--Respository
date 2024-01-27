#include <iostream>
using namespace std;

int main()
{
    int row,num;
    cout <<"Enter number of Rows : ";
    cin >> num;
    row = 1;

    while(row <= num)
    {

        //print space
        int space = num - row;
        while (space)
        {
            cout <<" ";
            space--;
        }
        //print stars
        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col ++;
        }
        cout << endl;
        row++;



    }
    return 0;
}