#include <iostream>
using namespace std;


//swap zero and one
void swapZeroOne(int arr[],int size)
{
    int start = 0;
    int end = size-1; //1,0,1,1,0,0 //0 0 1 0 1 1

    while(start < end)
    {
        if (arr[start] == 0)
        {
            start++;
        }
        if(arr[end] == 1)
        {
            end--;
        }
        if (arr[start] == 1 && arr[end] == 0)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
        
    }
    
}
//function to print array element

void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<endl;
    cout << "Printing Done.!"<<endl;
}

int main()
{
    int arr[6] = {1,0,1,1,0,0};
    
    swapZeroOne(arr,6);

    printArray(arr,6);

    return 0;
}