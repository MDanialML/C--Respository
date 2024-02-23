#include <iostream>
using namespace std;

void deleteElement(int *arr,int value,int size)
{
    int index = -1;

    for (int i = 0; i< size; i++)
    {
        if(arr[i] == value)
        {
            index = i;
        }
    }

    if(index != -1)
    {
        for (int i = index;i < size-1;i++)
        {
            arr[i] = arr[i+1];
        }
    }
    else
    {
        cout <<"element not found"<<endl;
    }
    
}


int main()
{
    int arr[5] = {5,6,8,2,3};
    int value = 8;
    int size = 5;

    //delete an element 
    deleteElement(arr,value,size);

    for(int i = 0; i < size-1;i++)
    {
        cout<<arr[i]<<",";
    }cout <<endl;

    return 0;
}