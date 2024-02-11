#include <iostream>
using namespace std;

//print array
void print(int *arr,int size)
{
    cout <<"Size :  "<<size << endl;

    for(int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
}

bool linearSearch(int *arr, int size, int key)
{
    print(arr,size);
    //base case
    if (size == 0)
    {
        return false;
    }
    //processing
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        // recursive relation
        bool remainingElement = linearSearch(arr + 1, size -1, key);
        return remainingElement;
    }
    
}


int main()
{
    int arr[6] = {3, 6, 9, 2, 7, 8};
    int size = 6;
    int key = 5;

    bool resp = linearSearch(arr, size, key);

    if (resp)
    {
        cout <<"Present.!"<<endl;
    }
    else
    {
        cout << "Absent.!"<<endl;
    }
    

}