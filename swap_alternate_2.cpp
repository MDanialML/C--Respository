#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {3,9,6,12,7,2};
    for (int i = 0; i < 6; i = i+2)
    {
        for (int j = i+1; j < i+1;j++)
        {
            swap(arr[i],arr[j]);
        }
    }
    //print array element
    for (int i = 0; i < 6;i++)
    {
        cout << arr[i]<<" ";
    }
    cout <<endl;
    return 0;
}