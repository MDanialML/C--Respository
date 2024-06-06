//heap sort max to min heap
#include<iostream>
using namespace std;

//heapify given array Max Heap
void heapify(int arr[],int size,int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if(leftChild <= size && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    } 
    if(rightChild <= size && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}

//heap sort convert max heap into min heap
void heapSort(int arr[],int size)
{
    int i = 1;
    while (size > 0)
    {
        swap(arr[i],arr[size]);
        size--;
        heapify(arr,size,i);
    }
}

int main()
{
    int arr[6] = {-1,3,2,1,4,5};
    int size = 5;
    for(int i = size/2; i > 0;i--)
    {
        heapify(arr,size,i);
    }
    cout<<"Printing max Heapified Array"<<endl;
    for(int i = 1; i <= size;i++)
    {
        cout<<arr[i]<<"   ";
    }cout<<endl;

    cout<<"HeapSort function started "<<endl;
    heapSort(arr,size);
    cout<<"Array after HeapSort from max to min"<<endl;
    for (int i = 1; i <= size; i++)
    {
        cout<<arr[i]<<"   ";
    }cout<<endl;
}