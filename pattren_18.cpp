#include <iostream>
using namespace std;


int main()
{
    int row, num;
    cout << "Enter number of Rows : ";
    cin >> num;
    row = 1;
    // int count = num;
    while (row <= num)
    {
        //print spaces
        int space = 1;
        while (space <= row)
        {
            cout << "@" <<" ";
            space++;
        }

        //print stars
        int col = num - row;
        while (col>= 0)
        {
            cout <<'*'<<" ";
            col--;

        }


        cout << endl;
        row++;
    }
}