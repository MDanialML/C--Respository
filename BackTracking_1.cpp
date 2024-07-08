#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> visited, vector<vector<int>>arr,int size)
{
    if((x >= 0 && x < size) && (y >= 0 && y < size) && (visited[x][y] != 1) && (arr[x][y] != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//function to get all poosible for a rat
void solve(int x, int y, vector<vector<int>> &arr, int size, vector<vector<bool>> &visited, vector<string>&ans,string path)
{
    //base case
    if(x == size-1 && y == size -1)
    {
        ans.push_back(path);
        return;
    }

    //movement
    //D L R U
    

    //mark visited true for current position
    visited[x][y] = 1;

    //Down
    if(isSafe(x+1, y, visited, arr, size))
    {
        solve(x+1, y, arr,size,visited,ans,path + 'D');
    }
    //Left
    if(isSafe(x-1,y,visited,arr,size))
    {
        solve(x-1,y,arr,size,visited,ans,path + 'L');
    }
    //Right
    if(isSafe(x,y+1,visited,arr,size))
    {
        solve(x,y+1,arr,size,visited,ans,path + 'R');
    }
    //Up
    if(isSafe(x-1,y,visited,arr,size))
    {
        solve(x,y-1,arr,size,visited,ans,path + 'U');
    }
    visited[x][y] = 0;
}


int main()
{
    //n*n array
    vector<vector<int>> arr = {{1,0,0,0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = arr.size();
    //visited array initialized with 0
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    //answer array
    vector<string> ans;
    //path
    string path = "";
    solve(0,0,arr, n, visited, ans, path);
    for(int i =0; i < ans.size();i++)
    {
        cout<<ans[i];
    }cout<<endl;
    /*
    for(int i =0; i < n;i++)
    {
        for(int j =0; j< n;j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
    for(int i =0; i < n;i++)
    {
        for(int j =0; j< n;j++)
        {
            cout<<visited[i][j]<<" ";
        }cout<<endl;
    }
    */
    return 0;
}