#include <iostream>
using namespace std;


//function to fetch the unique value
int uniqueElement(int arr[],int size)
{
    int unique = 0;
    for (int i = 0;i < size;i++)
    {
        unique = unique ^ arr[i];
    }
    cout <<"Search completed.!"<<endl;
    return unique;
}


int main()
{
    int arr_1[9] = {9,1,2,4,7,9,4,2,1};
    int size = 9;

    int unique = uniqueElement(arr_1,size);
    if (unique)
    {
        cout <<"Unique Element Found : "<<unique<<endl;
    }
    else
    cout <<"No unique element present."<<endl;
    return 0;
}