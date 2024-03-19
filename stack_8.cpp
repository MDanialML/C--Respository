#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>>M,int a,int b,int size)
{
    if(M[a][b] == 1)
    {
        return true;
    }else
    {
        false;
    }
}

int main()
{
    vector<vector<int>> M = {{0,1,0},{0,0,0},{0,1,0}};
    int size = M.size();
    //stack to hold 0,1,2
    stack<int> s;

    //first step 
    for (int  i = 0; i < size; i++)
    {
        s.push(i);
    }
    //second step
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        //condition to keep only potential celebrity candidate inside stack
        if(knows(M,a,b,size))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    //get potential celebrity candidate
    int candidate = s.top();
    //now verifying the celebrity
    //rowwise verification
    int zeroCount = 0;
    for(int i = 0; i < size; i++)
    {
        if(M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }
    //columnwise verification
    int oneCount = 0;
    for(int i =0; i< size; i++)
    {
        if(M[i][candidate] == 1)
        {
            oneCount++;
        }
    }

    if(zeroCount == size && oneCount == size - 1)
    {
        cout <<"There exist a celebrity, which is:   "<<candidate<<endl;
    }
    else
    {
        cout <<"No celebrity exist.!"<<endl;
    }
    return 0;
}