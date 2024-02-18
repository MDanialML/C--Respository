#include <iostream>
#include <vector>
using namespace std;

//check valid move
bool isSafe(vector<vector<int>>&maze,vector<vector<int>>&visited,int x,int y,int n)
{
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (maze[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void findPath(vector<vector<int>>&maze, int x,int y, int n,string path,vector<vector<int>>&visited,vector<string>&ans)
{
    //rat is at start position
    //base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    //moving down
    int newx = x+1;
    int newy = y;
    //check for valid move
    if(isSafe(maze,visited,newx,newy,n))
    {   
        cout<<"Moving Down"<<endl;
        path.push_back('D');
        findPath(maze,newx,newy,n,path,visited,ans);
        path.pop_back();

    }

      //moving Right
    newx = x;
    newy = y+1;
    //check for valid move
    if(isSafe(maze,visited,newx,newy,n))
    {
        cout<<"moving right"<<endl;
        path.push_back('R');
        findPath(maze,newx,newy,n,path,visited,ans);
        path.pop_back();

    }

      //moving left
    newx = x;
    newy = y-1;
    //check for valid move
    if(isSafe(maze,visited,newx,newy,n))
    {
        cout<<"Moving Left"<<endl;
        path.push_back('L');
        findPath(maze,newx,newy,n,path,visited,ans);
        path.pop_back();

    }

      //moving Up
    newx = x-1;
    newy = y;
    //check for valid move
    if(isSafe(maze,visited,newx,newy,n))
    {   
        cout<<"Moving Up"<<endl;
        path.push_back('U');
        findPath(maze,newx,newy,n,path,visited,ans);
        path.pop_back();

    }

    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    vector<string> ans;
    string path = "";
    int num = 4;
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = maze;

    //initialize all element as zero
    for (int i =0; i < num;i++)
    {
        for(int j = 0; j<num; j++)
        {
            visited[i][j] = 0;
        }
    }

    findPath(maze,srcx,srcy,num,path,visited,ans);


    //print ans vector
    for(int i =0; i < ans.size(); i++)
    {
        cout << ans[i],",";
    }
    cout<<endl;
    return 0;
}