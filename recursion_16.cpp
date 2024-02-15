#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
    //base case
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    //exclude 
    subsets(nums,output,index+1,ans); //recursive call
    //include
    int element = nums[index];
    output.push_back(element);
    subsets(nums,output,index+1,ans); //recursive call

}


int main()
{
    vector <int> nums = {3,5,8,6};
    vector <int>output;
    vector<vector<int>> ans;
    int index = 0;

    subsets(nums,output,index,ans);


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