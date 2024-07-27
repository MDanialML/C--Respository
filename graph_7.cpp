#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

//build a weighted graph
class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> graph;
    void buildGraph(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        graph[u].push_back(p);
    }
    //print graph
    void printGraph()
    {
        for(auto i: graph)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }cout<<endl;
        }
    }

    void dfs(int node, stack<int> &s, unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        for(auto neighbour: graph[node])
        {
            if(!vis[neighbour.first])
            {
                dfs(neighbour.first,s,vis);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
    {
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if(dist[top] != INT_MAX)
            {
                for(auto i : graph[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};


int main()
{
    Graph w_graph;
    int num_nodes = 6;
    w_graph.buildGraph(0, 1, 5);
    w_graph.buildGraph(0, 2, 3);
    w_graph.buildGraph(1, 2, 2);
    w_graph.buildGraph(1, 3, 6);
    w_graph.buildGraph(2, 3, 7);
    w_graph.buildGraph(2, 4, 4);
    w_graph.buildGraph(2, 5, 2);
    w_graph.buildGraph(3, 4, -1);
    w_graph.buildGraph(4, 5, -2);
    cout<<"Print weighted Graph:"<<endl;
    w_graph.printGraph();

    //Topological Sort
    int src = 0;
    stack<int> s;
    unordered_map<int, bool> visited;
    for(int i = 0; i< num_nodes; i++)
    {
        if(!visited[i])
        {
            w_graph.dfs(i, s, visited);
        }
    }

    //get shortest path
    int src_shortest = 1;
    vector<int>distance(num_nodes);
    for(int i = 0; i< num_nodes; i++)
    {
        distance[i] = INT_MAX;
    }
    w_graph.getShortestPath(src_shortest,distance, s);
    for(int i = 0; i< distance.size(); i++)
    {
        cout<<distance[i]<<",";
    }cout<<endl;
    return 0;
}