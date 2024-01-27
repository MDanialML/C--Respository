#include <iostream>
using namespace std;

//function to sort an array
void insertionSort(int arr[],int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;

        for (; j >= 0; j--)
        {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        // cout << "Round number #     "<<i<<endl;
        arr[j+1] = temp;
    }
    // cout <<"|||||||||||||||||||||**************************|||||||||||||||||||||||"<<endl;
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

int main(){
    int arr[7] = {2,7,4,8,3,9,5};
    
    //function call
    insertionSort(arr,7);

    //function call 
    printArray(arr,7);

    return 0;
}