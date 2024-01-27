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
        int col = 1;
        int count = num;
        while(col <= num)
        {
            cout << count;
            count--;
            col++;

        }
        cout << endl;
        row ++;
    }
    return 0;
}