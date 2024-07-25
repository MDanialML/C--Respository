#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;


int main()
{
    unordered_map<int, list<int>> adjc;
    vector<int> ans;
    int num_nodes;
    int num_edges;
    cout<<"Enter number of Nodes:"<<endl;
    cin>>num_nodes;
    cout<<"Enter number of edges:"<<endl;
    cin>>num_edges;
    cout<<"Enter each edge in the form of pair:"<<endl;
    for(int i = 0; i < num_edges;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        adjc[u].push_back(v);
    }
    cout<<"Print the Graph:"<<endl;
    for(auto i : adjc)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }cout<<endl;
    }
    
    //get indegree of each node
    vector<int> in_degree(num_nodes+1);
    for(auto i : adjc)
    {
        for(auto j : i.second)
        {
            in_degree[j]++;
        }
    }
    //Now insert node into queue whoes indegree is equal to zero
    queue<int> q;
    for(int i = 1; i < in_degree.size();i++)
    {
        if(in_degree[i]== 0)
        {
            q.push(i);
        }
    }
    //do breadth first search
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour: adjc[front])
        {
            in_degree[neighbour]--;
            if(in_degree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    for(auto i : ans)
    {
        cout<<i<<",";
    }cout<<endl;
    return 0;
}