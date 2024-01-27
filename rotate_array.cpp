#include <iostream>
using namespace std;


//rotate array
void rotateArray(int arr[],int size,int k)
{
    int rot[size];
    for (int i = 0; i < size; i++)
    {
        rot[(i+k)%size] = arr[i]; //it will shift the ith element in cyclic way
    }

    //copy the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = rot[i];
        }

}

//print array
void printArr(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
    cout <<"Printing Done"<<endl;
}

int main(){
    int arr[6] = {2,3,4,7,9,11};
    int k = 3; //number of indexes to move an element

    rotateArray(arr,6,k);

    printArr(arr,6);
    return 0;
}
