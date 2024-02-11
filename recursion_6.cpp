#include <iostream>
using namespace std;


bool isSorted(int *arr, int size)
{
    //Base case
    if(size == 0 || size == 1)
    {
        return true;
    }
    //Processing
    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        //recursive relation
        bool response = isSorted((arr + 1), (size - 1));
        return response;
    }
    

}

int main()
{
    // int arr[10] = {5,6,7,7,8,9,10,10,13,14};
    int arr[10] = {5,6,7,7,8,14,10,10,13,14};

    int response = isSorted(arr,10);

    if(response)
    {
        cout << "Array is sorted: "<<endl;
    }
    else
    {
        cout << "Array is not sorted: "<< endl;
    }

    return 0;
}