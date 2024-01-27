// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

#include <iostream>
using namespace std;

//merging two array
void mergeArray(int arr1[],int size1,int arr2[],int size2){
    int i = size1 - 1; //iterator for array 1
    int j = size2 -1; //iterator for array 2
    int k = (size1 + size2) -1;

    while(i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
            k--;
        }
        else{
            arr1[k] = arr2[j];
            j--;
            k--;
        }
    }

    while(i >= 0)
    {
        arr1[k] = arr1[i];
        i--;
        k--;
    }
}

//print array
//print array
void printArray(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    cout << "Printing Done.!"<<endl;
}

int main()
{
    int arr1[6] = {1,2,3,0,0,0};
    int arr2[3] = {2,5,6};

    mergeArray(arr1,3,arr2,3);

    printArray(arr1,6);

    return 0;
}

