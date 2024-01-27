#include <iostream>
using namespace std;

//function search linearly
bool searchArray(int arr[],int size,int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;

}


int main()
{
    int arr[10] = {10,20,43,67,-1,-4,89,23,9,10};
    int size = sizeof(arr)/4;
    cout << "Size of array is : "<<size<<endl;
    int key;
    cout << "Enter key to search for :      ";
    cin >> key;
    cout << endl;
    bool found = searchArray(arr,size,key);
    if (found)
    {
        cout <<"Key available"<<endl;
    }
    else
    {
        cout <<" Key not available";
    }

    return 0;

}