#include <iostream>
using namespace std;


void sortArray(int *arr,int start,int end)
{
    //base case
    if (start >= end)
    {
        return;
    }

    for(int i = start; i < end;i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    //recursive call
    sortArray(arr,start,end-1);
}

int main()
{
    int arr[10] = {2,5,3,6,8,8,9,2,1,7};
    int start =0;
    int end = 10;

    sortArray(arr,start,end-1);

    int min = arr[0];
    int max = arr[end-1];
    cout <<"Minimum:    "<<min<<"   Maximum:     "<<max<<endl;

    for (int i = 0; i <end; i++)
    {
        cout << arr[i];
    }
    cout <<endl;

    return 0;
}