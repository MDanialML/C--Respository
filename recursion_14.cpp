#include <iostream>
using namespace std;


void mergeArray(int *arr, int start, int end)
{
    int mid = start + (end - start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *leftArray = new int(len1);
    int *rightArray = new int(len2);

    //copy parrent array left part to left array
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        leftArray[i] = arr[mainArrayIndex++];
    }

    //copy parrent array right part to right array
    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++)
    {
        rightArray[i] = arr[mainArrayIndex++];
    }

    //merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2)
    {
        if (leftArray[index1] < rightArray[index2])
        {
            arr[mainArrayIndex++] = leftArray[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = rightArray[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[mainArrayIndex++] = leftArray[index1++];
    }
    while(index2 < len2)
    {
        arr[mainArrayIndex++] = rightArray[index2++];
    }

    


}

void mergeSort(int *arr, int start,int end)
{
    //Base case
    if(start >= end)
    {
        return;
    }
    int mid = start + (end - start)/2;

    //recursive call
    //left half
    mergeSort(arr,start, mid);
    
    //rigth half
    mergeSort(arr,mid+1, end);

    mergeArray(arr,start,end);

}


int main()
{
    int arr[7] = {99,44,67,57,88,0,8};
    int start = 0;
    int end = 7;

    mergeSort(arr, start, end-1);

    for(int i =0; i < end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout <<endl;

    return 0;
}