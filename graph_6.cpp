#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    //Creat adjacency list
    cout<<"Enter number of Nodes:"<<endl;
    int num_nodes;
    cin>> num_nodes;
    cout<<"Enter Number of Edges: "<<endl;
    int num_edges;
    cin>> num_edges;
    unordered_map<int,list<int>> adjc;
    cout<<"Enter edges on by one in Pair:"<<endl;
    for(int i = 0; i < num_edges; i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        adjc[u].push_back(v);
        adjc[v].push_back(u);
    }
    cout<<"Print Undirected graph: "<<endl;
    for(auto i : adjc)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }cout<<endl;
    }
    
    //do bfs
    queue<int>q;
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    int src = 1;
    parent[src] = -1;
    visited[src] = true;
    q.push(src);
    //start bfs
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto i : adjc[front])
        {
            if(!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    /*
    for(auto i : parent)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }*/
   //prepare shortest path

    int destination = 8;
    vector<int> ans;
    ans.push_back(destination);
    while (destination != src)
    {
        destination = parent[destination];
        ans.push_back(destination);
    }

    reverse(ans.begin(),ans.end());
    for(auto i : ans)
    {
        cout<<i<<"->";
    }cout<<endl;

    return 0;
}