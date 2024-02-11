#include <iostream>
using namespace std;


int sumArray(int *arr, int size)
{
    //base case
    if (size == 0)
    {
        return 0;
    }
    if(size == 1)
    {
        return arr[0];
    }

    // recursive relation
    int remainElement = sumArray((arr + 1), (size - 1));
    //processing
    int sum = arr[0] + remainElement;
    return sum;

}



int main()
{
    int arr[7] = {5,8,4,9,2,6,10};

    int sum = sumArray(arr,7);
    cout <<"Sum of array elements: "<<sum<<endl;

    return 0;
}