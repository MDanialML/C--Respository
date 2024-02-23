#include <iostream>
using namespace std;

void insertElement(int *arr,int pos,int value,int size)
{
    if (0 <= pos && pos < size)
    {
        for(int i = size-1; i > pos; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[pos] = value;
    }
}

int main(){
    int arr[6] = {2,3,4,6,8};
    int pos = 3;
    int value = 100;
    int size = 6;

    //insert an element
    insertElement(arr,pos,value,size);

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<",";
    }cout<< endl;
}