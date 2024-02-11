#include <iostream>
using namespace std;

void print(int *arr, int s,int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i]<<" ";

    }
    cout <<endl;
}


bool binarySearch(int *arr, int start, int end, int value)
{
    cout<<endl;
    print(arr,start,end);
    //base case
    //if element not found
    if (start > end)
    {
        return false;
    }
    //calculate mid
    int mid = start + (end - start)/2;
    
    //if element found
    if(arr[mid] == value)
    {
        return true;
    }

    //recursive relation

    if(arr[mid] < value) //move to right half of array
    {
        return binarySearch(arr, (mid + 1), end, value);
    }
    if(arr[mid] > value)
    {
        return binarySearch(arr, start, (mid - 1), value);
    }
}


int main()
{
    int arr[8] = {6,4,7,8,9,12,14,18};
    int value = 18;

    bool response = binarySearch(arr,0, (8-1),value);

    if (response)
    {
        cout <<"Element found.!"<<endl;
    }
    else
    {
        cout <<"Element not found.!"<<endl;
    }
    
    return 0;
}