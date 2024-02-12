#include <iostream>
using namespace std;


void sortArray(int *arr,int size)
{
    //base case 
    if(size == 0 || size == 1)
    {
        return;
    }
    
    for (int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }

    //recursive relation
    sortArray(arr, size - 1);

}

int main()
{
    int arr[9] = {3,8,9,1,2,5,7,6,4};

    sortArray(arr,9);

    for(int i = 0; i <9; i++)
    {
        cout <<arr[i]<<" ";

    }
    cout <<endl;
    return 0;
}