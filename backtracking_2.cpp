#include <iostream>
#include<vector>
using namespace std;

//utility function for checking queen placement is safe or not
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    //check for same row
    int x = row;
    int y = col;
    while(y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    //check for upper diagonal
    x = row;
    y = col;
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    //check for lower diagonal
    x = row;
    y = col;
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

//function for adding solution into answer
void addSolution(vector<vector<int>> &board,vector<vector<int>>&ans, int n)
{
    vector<int> temp;
    for(int i = 0; i<n; i++ )
    {
        for(int j =0; j< n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

//function to slove N-Queen problem and place at a safe place
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board,int n)
{
    //base case
    if(col == n)
    {
        addSolution(board,ans, n);
        return;
    }

    //solve one case rest recurrsion will take care
    for(int row =0; row < n; row++)
    {
        if(isSafe(row,col,board,n))
        {
            //if palcing queen is safe
            board[row][col] = 1;
            //recurrsive call for rest of board
            solve(col+1,ans,board,n);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n,vector<int>(n,0));
    //solved board for N-queens
    vector<vector<int>> ans;

    solve(0,ans,board,n);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j =0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}