#include <iostream>
using namespace std;

int main()
{
    int row,num;
    cout << "Enter number of lines : ";
    cin >> num;
    row = 1;
    while (row <= num)
    {
        //print spaces first triangle
        int space = num - row;
        while(space)
        {
            cout <<" ";
            space --;
        }

        //print sequences Second triangle
        int col = 1;
        while(col <= row)
        {
            cout << col << " ";
            col++;
        }
        //third triangle
        int start = row - 1;
        while(start)
        {
            cout << start<<" ";
            start--;
        }
        cout << endl;
        row ++;
    }
    return 0 ;
}