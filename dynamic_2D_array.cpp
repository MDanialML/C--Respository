#include <iostream>
using namespace std;


int main()
{
    int row;
    int col;
    cout <<"Enter number of rows : "<<endl;
    cin >> row;
    cout << "Enter number of columns : "<<endl;
    cin >> col;
    

    ///dynamic 2D array declaration
    int **arr = new int*[row];
    for (int  i = 0; i < row; i++)
    {
        arr[i] = new int[col];

    }

    //now taking array elements
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    //print element
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }

    //now freeing up the heap memory
    for (int i = 0; i < row; i++)
    {
        delete []arr[i];
    }

    delete []arr;

    cout <<"Memory freedup.!!"<<endl;

    return 0;
}