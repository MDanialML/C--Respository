#include <iostream>
using namespace std;

//sort three digit in asceding order
void sortArray(int arr[],int size)
{
    int left = 0;
    int right = size - 1;
    int i = 0;
    while(i <= right)
    {

        if (arr[i] == 0)
        {
            swap(arr[i],arr[left]);
            i++;
            left++;
           
        }
        if   (arr[i] == 2)
        {
             swap(arr[i],arr[right]);
            right--;

        }
        if((arr[i] == 1) && (arr[right] == 0))
        {
            swap(arr[i],arr[right]);
        }
        
        i++;
        
       
    }

}



//print array
void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Printing Done.!"<<endl;
}


int main()
{
    int arr[9] = {0,1,2,2,0,0,1,0,2};


    //sort array
    sortArray(arr,9);

    //print array
    printArray(arr,9);

    return 0;
}