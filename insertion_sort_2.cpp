#include <iostream>
using namespace std;

//sort an array

void sortArray(int arr[],int size)
{
    int i = 1;
    while(i < size){
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > temp)
        {
                arr[j+1] = arr[j];
                j--;
                
        }
        arr[j+1] = temp;
        i++;
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
    int arr[9] = {7,5,6,4,2,11,9,1,8};

    sortArray(arr,9);

    printArray(arr,9);

    return 0;
}