#include <iostream>
using namespace std;

//binary search function
int binarySearch(int arr[],int size,int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        // now deciding where to go left or right
        if (arr[mid] < key) //toward right of array
        {
            start = mid + 1; 
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;

    }
    return -1;
}

int main()
{
    int even[8] = {2,3,4,56,67,76,87,97};
    int odd[5] = {3,4,5,6,7};

    int evenSearch = binarySearch(even,8,97);
    cout<<"Index of key 97 is :"<<evenSearch <<endl;

    int oddSearch = binarySearch(odd,5,5);
    cout<<"Index of key 5 is :"<<oddSearch <<endl;

    return 0;
}