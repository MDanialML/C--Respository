#include <iostream>
using namespace std;


int main()
{
    int arr[7] = {1,2,9,6,5,4,1};
    int start = 0;
    int end = 7-1;
    int mid = start +(end - start)/2;
    while(start < end){
        if (arr[mid] < arr[mid+1])
        {
            start = mid + 1;
        }
        else {
            end = mid;
        }
        mid = start + (end - start)/2;

    }
    cout <<arr[mid]<<endl;

}
