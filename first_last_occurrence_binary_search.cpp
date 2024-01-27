#include <iostream>
using namespace std;


//first occurrence
int firstOccurrence(int arr[],int size,int key)
{
    int start = 0;
    int end = size -1 ;
    int occurrence = -1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if (arr[mid] == key)
        {
        occurrence = mid;
        end = mid - 1;
        }
        //forward
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else if (key < arr[mid]) //backward
        {
            end = mid - 1;

        }
        mid = start + (end - start)/2;
    }
    return occurrence;
}

//last occurrence
int lastOccurrence(int arr[],int size,int key)
{
    int start = 0;
    int end = size -1 ;
    int occurrence = -1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if (arr[mid] == key)
        {
        occurrence = mid;
        start = mid + 1;
        }
        //forward
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else if (key < arr[mid]) //backward
        {
        end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return occurrence;
}
int main(){
    int data[9] = {2,3,4,5,5,5,5,5,9};

    cout <<"First occurrence index is : "<<firstOccurrence(data,9,5)<<endl;
    cout <<"Last occurrence index is : "<<lastOccurrence(data,9,5)<<endl;

    int total_occurrenc = ((lastOccurrence(data,9,5)) - (firstOccurrence(data,9,5)))+ 1;
    cout <<"Total number of occurrence is : "<<total_occurrenc<<endl;


    return 0;
}