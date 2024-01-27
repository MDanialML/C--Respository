#include <iostream>
using namespace std;

int main()
{
    int row, num;
    cout << "Enter number of Rows : ";
    cin >> num;
    row = 1;
    while (row <= num)
    {
        char start = 'A' + row -1;
        int col = 1;
        while (col <= num)
        {
            // start = start + col -1;
            cout << start << " ";
            start++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}