#include<bits/stdc++.h>
using namespace std;


//function to get kth smallest element
int kthSmallestElement(int arr[],int k,int size)
{
    priority_queue<int> pq; //for finding kth largest element in an array we need a min heap priority_queue<int,vector<int>,greater<int>>
    
    //Step 1
    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    //step 2
    for (int i = k; i < size; i++)
    {
        if(arr[i] < pq.top()) // for kth largest element we just need to change the condition from less than to greater than
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //step 3
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[5] = {7,10,4,20,15};
    int ans = kthSmallestElement(arr,4,5);
    cout<<"Kth smallest element is:   "<<ans<<endl;
    return 0;
}