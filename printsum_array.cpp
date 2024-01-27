#include <iostream>
using namespace std;

//function to get sum of all array element
int sumArray(int arr[],int size)
{
    int sum = 0;
    for (int i = 0 ; i < size ; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}



int main()
{
    int arr[50];
    int size ;
    cout <<"size of array:      ";
    cin >> size;
    cout<<endl;
    cout << "Enter elements :   ";
    for (int i =0; i < size; i++)
    {
        cin >> arr[i];
    }

    int sum = sumArray(arr,size);
    cout <<"Sum of all elements: "<<sum<<endl;
    return 0;
}