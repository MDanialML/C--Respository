#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;

//Topological sort utility function
void topologicalSort(int node,unordered_map<int, bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adjc)
{
    visited[node] = 1;
    for(auto neighbour: adjc[node])
    {
        if(!visited[neighbour])
        {
            topologicalSort(neighbour,visited,s,adjc);
        }
    }
    //most important and main statement
    s.push(node);
}

int main()
{
    unordered_map<int, list<int>> adjc;
    int num_node;
    int num_edges;
    cout<<"Enter number of Nodes:   "<<endl;
    cin>>num_node;
    cout<<"Enter number of Edges: "<<endl;
    cin>>num_edges;
    cout<<"Edges pair by pair"<<endl;
    for(int i = 0; i< num_edges;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        adjc[u].push_back(v);
    }
    //print graph
    cout<<"Now printing graph: "<<endl;
    for(auto i : adjc)
    {
        cout<<i.first<<"->";
        for(auto j: i.second)
        {
            cout<<j<<",";
        }cout<<endl;
    }
    //dfs topological sort function
    unordered_map<int, bool> visited;
    stack<int> s;
    vector<int> ans;
    for(int i = 1; i <= num_node; i++)
    {
        if(!visited[i])
        {
            topologicalSort(i,visited,s,adjc);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for(int i =0; i < ans.size();i++)
    {
        cout<<ans[i]<<",";
    }cout<<endl;
    return 0;
}