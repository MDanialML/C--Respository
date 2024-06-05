#include <iostream>
#include<vector>
using namespace std;

//Heap implementation and insertion
class Heap{
    public:
    int arr[100];
    int size;
    //constructor
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    
    //function to insert into heap
    void insertHeap(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        //check for correct insertion
        while (index > 1)
        {
            int parent = index / 2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    //delete from heap
    void deleteFromMaxHeap()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete.!"<<endl;
            return;
        }
        //swap last element with root
        arr[1] = arr[size];
        size--; //decrease size so the last element become un accessable
        //now move root element to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i; //get left child index
            int rightIndex = 2 * i + 1; //get right child index
            //check left child
            if(leftIndex < size && arr[i] < arr[leftIndex]) //check for underflow condition && maxheap condition for left child
            {
                swap(arr[i],arr[leftIndex]); //if above condition is true then swap parent with its left child
                i = leftIndex; //move index from parent to child
            }
            if (rightIndex < size && arr[i] < arr[rightIndex]) //check fro underflow condition && maxheap condition for right child
            {
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return; //if botht condition are not true its mean it is a valid maxheap return
            }
        }
    }

    void print()
    {
        for(int i = 1; i <= size;i++)
        {
            cout<<arr[i]<<"   ";
        }cout<<endl;
    }
};

int main()
{
    Heap heap;
    heap.insertHeap(6);
    heap.insertHeap(1);
    heap.insertHeap(5);
    heap.insertHeap(4);
    heap.insertHeap(3);
    heap.insertHeap(7);
    heap.insertHeap(2);
    heap.print();
    heap.deleteFromMaxHeap();
    heap.print();
    return 0;
}