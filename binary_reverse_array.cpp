#include <iostream>
using namespace std;

//reverse order

void reverseArray(int arr[],int size)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

//print array
void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    cout << "Printing Done.!"<<endl;
}

int main()
{
    int arr[9] = {9,8,7,6,5,4,3,2,1};

    reverseArray(arr,9);

    printArray(arr,9);

    return 0;
}