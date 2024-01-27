#include <iostream>
using namespace std;

//function to sort array
void bubbleSort(int arr[],int size)
{
    for (int i = 0; i < size-1; i++)// this loop show number of round
    {
        bool isswap = false; //optimized for best case
        for (int j = 0; j< size - i -1 ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isswap = true;
            }
        }

        if (isswap == false){ 
            break;
        }

    }
}

//print array
void printArray(int arr[],int size)
{
    for (int i = 0 ; i < size; i ++)
    {
        cout << arr[i]<< " ";

    }
    cout <<endl;
    cout << "Printing Done.!"<<endl;
}

int main()
{
    int arr[7] = {9,16,7,8,10,3,11};
    
    bubbleSort(arr,7);

    printArray(arr,7);

    return 0;
}
