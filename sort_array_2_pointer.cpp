#include <iostream>
using namespace std;

//printing array
void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
    cout <<"Printing Done.!"<<endl;

}



//sorting array
void sortArray(int arr[],int size)
{
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
    
    if ((arr[start] == 1) & (arr[end] == 0) )
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    if (arr[start] == 0)
    {start++;}
    if(arr[end] == 1)
    {end--;}
    
    }
}


int main()
{
    int arr[11] = {1,1,0,1,0,0,0,1,1,0,1};
    sortArray(arr,11);

    printArray(arr,11);

    return 0; 
}
