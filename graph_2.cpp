#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

//graph 
class Graph{
    public:
    unordered_map<int,list<int>> adj_list;
    //insert vertices
    void addEdge(int u, int v, bool direction)
    {
        adj_list[u].push_back(v);
        //check for undirected graph
        if(direction == 0)
        {
            adj_list[v].push_back(u);
        }
    }

    //print node and adjacent nodes
    void printAdjacentNodes()
    {
        for(auto i : adj_list)
        {
            cout<<i.first<<"->";
            for (auto j: i.second)
            {
                cout<<j<<",";
            }cout<<endl;
        }
    }
};

//BFS Traversal
void BFSTraversal(unordered_map<int,list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        //treverse all neighbour nodes
        for (auto i: adjList[node])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    
}


int main()
{
    Graph first_graph;
    int node;
    cout<<"Enter number of Nodes:   "<<endl;
    cin>> node;
    int edges;
    cout<<"Enter number of edges: "<<endl;
    cin>>edges;
    //connecting nodes according to given nodes
    //enter pair of connected nodes
    cout<<"Enter connected nodes in the form of pair"<<endl;
    for (int i =0; i < edges;i++)
    {
        int u,v;
        cin>>u>>v;
        first_graph.addEdge(u,v,0);
    }
    cout<<"Now printing graphs"<<endl;
    first_graph.printAdjacentNodes();

    //Breadth first Search
    unordered_map<int, bool> visited;
    vector<int> ans;
    int f_node = 0;
    
    for(int i =0; i < node; i++)
    {
        visited[i] = 0;
    }

    //excute bfstraversal for all nodes
    
    BFSTraversal(first_graph.adj_list,visited,ans, f_node);
    for(int i =0 ; i < ans.size();i++)
    {
        cout<<ans[i]<<",";
    }cout<<endl;
    return 0;
}