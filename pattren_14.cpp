#include <iostream>
using namespace std;

int main()
{
    int row, num;
    cout << "Enter number of Rows : ";
    cin >> num;
    row = 1;
    while(row <= num)
    {
        int col = 1;
        while (col <= row)
        {
            char ch = 'A' + num - col;
            cout << ch << " ";
            col ++;
        }
        row++;
        cout<<endl;
    }
    return 0;
}