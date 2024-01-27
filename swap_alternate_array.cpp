#include <iostream>
using namespace std;


//print elements
void printArray(int arr[],int size)
{
    for (int i = 0;i < size;i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Print Done.!";
}


//function to do swaping
void swapAlternate(int arr[],int size)
{
    for (int i = 0; i < size; i=i+2)
    {
        int temp = arr[i];
        if (i + 1 < size)
        {
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        
    }
    cout <<"Swapping Done..!"<<endl;

}

int main()
{
    int arr_a[8] = {4,5,6,7,8,9,1,2};
    int arr_b[5] = {9,0,1,8,6};

    swapAlternate(arr_a,8);
    printArray(arr_a,8);


    swapAlternate(arr_b,5);
    printArray(arr_b,5);
    

    return 0;
}