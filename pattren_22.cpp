#include <iostream>
using namespace std;

int main()
{
    int num;
    cout <<"Enter number of rows:   ";
    cin >> num;
    cout << endl;
    int row = 1;
    int count = num * num;
    while(row <= num)
    {
        int col = 1;
        while (col <= num)
        {
            cout << count << " ";
            col ++;
            count --;
        }
        cout << endl;
        row ++;
    }
    return 0;
}