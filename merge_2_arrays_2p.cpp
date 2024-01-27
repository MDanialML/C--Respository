#include <iostream>
using namespace std;


//merge array

void mergeArray(int arr1[],int size1,int arr2[],int size2,int arr3[])
{
    int i = 0, j = 0;
    int end1 = size1 - 1;
    int end2 = size2 - 1;
    int k = 0;

    while((i <= end1) && (j <= end2))
    {
        if (arr1[i] < arr2[j] )
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    //remaining element of array 1
    while (i < end1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < end2)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
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
    int arr1[4] = {1,2,4,6};
    int arr2[8] = {3,5,7,9,11,13,15,19};

    int arr3[12] = {0};

    //function call
    mergeArray(arr1,4,arr2,8,arr3);

    printArray(arr3,12);
    return 0;
}