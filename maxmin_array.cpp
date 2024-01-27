#include <iostream>
using namespace std;
#include <climits>

//printing the values of array
// void printArray(int arr[],int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         cout << arr[i]<<" ";
//     }
//     cout << endl;
//     cout <<"Printing Done";
// }

//function to fetch maximum value from a given array
int maxNum(int arr[],int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout <<"Coparison Done..!!"<< endl;
    return max;
}

//function to fetch minimum value from the given array
int minNum(int arr[],int size)
{
    int min = INT_MAX;
    for (int i =0; i < size; i++){
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Comparison is Done..!"<<endl;
    return min;
}


int main ()
{
    int size;
    cout <<"Enter size of array:    "<<endl;
    cin >> size;

    //array declaration
    int arr[100];
    cout<<"Enter sequence of values:    ";
    for (int i = 0;i < size;i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    // printArray(arr,size);
    int max = maxNum(arr,size);
    cout <<"Maximum value of given Array is : "<<max <<endl;
    cout << "       _______________________________     "<<endl;
    int min = minNum(arr,size);
    cout <<"Minimum of all values: "<<min;
}