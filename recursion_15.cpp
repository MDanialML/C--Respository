#include <iostream>
using namespace std;

int partition (int *arr, int s, int e)
{
    //pivot element
    int pivot = arr[s];
    int count = 0;
    for (int i = s+1; i<e;i++)
    {
        if (arr[i] <= pivot)
        {
            count = count + 1;
        }
    }

    int pivotindex = s + count;
    //place pivot at right place
    swap(arr[s], arr[pivotindex]);

    //now deal with left and right part of pivot
    int i = s,j = e;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        
        if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j--]);
        }
        
    }
    
    return pivotindex;
}



void quickSort(int *arr, int s, int e)
{
    //Base case
    if (s >= e)
    {
        return;
    }

    int p = partition(arr,s,e); 
    //recursive call
    quickSort(arr, s, p-1);

    quickSort(arr,p+1,e);
}

int main()
{
    int arr[11] = {3,55,2,44,32,0,9,2,44,6,5};

    cout<<"Array befor sorting"<<endl;
    for (int i = 0; i < 11;i++)
    {
        cout <<arr[i]<<" ";
    }cout <<endl;

    quickSort(arr, 0,11-1);

    for (int i = 0; i < 11;i++)
    {
        cout <<arr[i]<<" ";
    }cout <<endl;
    return 0;
}