#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> ans;
    int arr[5] = {10,5,5,5,2};
    int sum = 12;

    for (int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                if(arr[i] + arr[j] + arr[k] == sum)
                {
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[k]);
                    }
                // cout <<i<<" "<<j<<" "<<k<<endl;
                
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << ans[i]<< " ";
    }
}