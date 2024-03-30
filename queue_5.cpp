#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    int arr[7] = {-2,4,3,4,6,5,-9};
    deque<int> dq;
    vector <int> ans;
    int k = 2;
    int len = sizeof(arr)/sizeof(arr[0]);
    
    //get negative element from first window
    for(int i = 0; i < k; i++)
    {
        if(arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    //save negative element into ans
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    //process remaining array
    for(int i = k; i < len; i++)
    {
        //remove element outside window
        if(!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        //get negative element from window
        if(arr[i] < 0)
        {
            dq.push_back(i);
        }

        //save negative element into ans
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    for(int i =0; i < ans.size(); i++)
    {
        cout <<": "<<ans[i];
    }cout<<endl;

    return 0;
}

