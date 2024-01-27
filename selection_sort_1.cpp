#include <iostream>
using namespace std;


//sorting an array

void selectSort(int arr[],int size)
{
    for (int i = 0; i < size -1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if ( arr[j] < arr[minIndex])
            {
                minIndex = j;
            }

        }
        swap(arr[i],arr[minIndex]);
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
    int arr[9] = {4,2,8,9,7,11,10,3,12};
    
    //sort
    selectSort(arr,9);

    //print 
    printArray(arr,9);

    return 0;
}