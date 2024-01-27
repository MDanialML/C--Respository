#include <iostream>
using namespace std;

//function to swap elements
void reverse(int arr[],int n)
{
    int start = 0;
    int end = n-1;
    while(start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


//function to print that array
void printArr(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
    cout <<"Printing Done"<<endl;
}

int main()
{
    int arr1[6] = {3,4,5,6,7,8};
    int arr2[5] = {9,8,7,6,5};

    reverse(arr1,6);
    reverse(arr2,5);
    printArr(arr1,6);
    printArr(arr2,5);
    
    return 0;

}