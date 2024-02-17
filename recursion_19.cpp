#include <iostream>
#include <vector>
using namespace std;


void permutation(vector<int>nums,int index,vector<vector<int>>&ans)
{
    //base case
    if(index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int j = index; j < nums.size();j++)
    {
        swap(nums[index],nums[j]);
        permutation(nums,index+1,ans);
        swap(nums[j],nums[index]);
    }
}

int main()
{
    vector <int> nums = {1,2,3};
    vector<vector<int>> ans;
    int index = 0;

    permutation(nums,index,ans);

    for (int  i = 0; i < ans.size(); i++)
    {
        cout <<"{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
    cout <<endl;

    return 0;
}