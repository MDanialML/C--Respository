//heapify a Binary Tree
#include <iostream>
using namespace std;

void heapify(int arr[],int size, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if(leftChild <= size && arr[largest] < arr[leftChild]) //check if left Child of target node is greater 
    {
        largest = leftChild; //update largest index with leftchild index
    }
    if(rightChild <= size && arr[largest] < arr[rightChild]) //check if right child of target node is greater
    {
        largest = rightChild; //update largest index with right child index
    }
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

int main()
{
    int arr[6] = {-1, 54,53,55,50,52}; 
    int size = 5;
    for (int i = size/2; i > 0; i--)
    {
        heapify(arr,size,i);
    }
    cout<<"Print Heapified Array:   "<<endl;
    for (int i = 1; i <= size; i++)
    {
        cout<<arr[i]<<"   ";
    }cout<<endl;
    return 0;
}