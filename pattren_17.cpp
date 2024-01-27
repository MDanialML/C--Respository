#include <iostream>
using namespace std;

int main()
{
    int row,num;
    cout <<"Enter number of Rows : ";
    cin >> num;
    row = 1;
    int count = num;
    while (row <= num)
    {
        int col = 1;
        while(col <= count)
        {
            char ch = '*';
            cout << ch;
            col ++;
        }
        count = count - 1;
        row ++;
        cout << endl;
    }
    return 0;
}