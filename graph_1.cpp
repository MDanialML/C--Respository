#include <iostream>
#include<unordered_map>
#include <list>
using namespace std;

//grap implementaion using adjacency list
class graph{
    public:
    unordered_map<int, list<int>> adj;

    //function to create edges
    //need first and second vertice/node
    //need direction 1 if graph is directed, 0 if graph is undirected
    void insertEdges(int u, int v, bool direction)
    {
        //create a edge from u to v
        adj[u].push_back(v);
        //check for direction
        if(direction == 0)
        {
            //graph is undirected so create an edge from v to u as well
            adj[v].push_back(u);
        }
    }
    //print graph
    void printGraph()
    {
        for(auto i: adj)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
            {
                cout<<j<<",";
            }cout<<endl;
        }
    }
};


int main()
{
    //creat a graph
    graph g;
    int num_node;
    cout<<"Enter number of nodes:   "<<endl;
    cin>>num_node;
    int num_edges;
    cout<<"Enter number of edges:   "<<endl;
    cin>>num_edges;
    //create edges between nodes
    cout<<"Enter "<< num_edges<<"edges: "<<endl;
    for(int i = 0; i < num_edges; i++)
    {
        int u,v;
        cin>>u>>v;
        //creating an undirected graph for given edges
        g.insertEdges(u,v,0);
    }
    //now printing the graph
    g.printGraph();
    return 0;
}