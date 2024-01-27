#include <iostream>
using namespace std;

int main()
{
    int row,num;
    cout << "Enter number of Rows : ";
    cin >> num;
    row = 1;

    while (row <= num)
    {
        
    //first pattren
        int col = 1;
        while(col <= num - row + 1)
        {
            cout << col<<" ";
            col ++;
        }
    //second pattren
    col = 1;
    while(col <= (row - 1)* 2)
    {
        cout << "* ";
        col++;
    }
    //third pattren
    //int count = num;
    //col = 1;
    int cond = num - row + 1;
    while(cond)
    {
        cout << cond<< " ";
        cond --;
    }
    

     cout <<endl;
    row ++;
    }

    

    

    //fourth pattren
}