#include<bits/stdc++.h>
using namespace std;

//kth largest sub array sum
int kthLargestSA(vector <int> &arr,int k)
{
    int size = arr.size();
    vector<int> sumArray;
    priority_queue<int, vector<int>, greater<int>> pq;


    for(int i = 0; i < size;i++)
    {
        int sum = 0;
        for(int j = i; j < size;j++)
        {
            sum += arr[j];
            // sumArray.push_back(sum);
            if(pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if(sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
            
        }
    }
    // sort(sumArray.begin(), sumArray.end());
    return pq.top();
}

int main()
{
    vector<int> arr = {4,2,8,3};
    int k =2;
    cout<<kthLargestSA(arr,k)<<endl;
    return 0;
}