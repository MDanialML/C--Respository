#include<iostream>
#include<unordered_map>
#include<limits.h>
#include<vector>
#include<list>
using namespace std;


int main()
{
    int num_node;
    cout<<"Enter number of Nodes: "<<endl;
    cin>> num_node;
    int num_edges;
    cout<<"Enter number of Edges: "<<endl;
    cin>> num_edges;
    cout<<"Enter Edges and their respective weights: "<<endl;
    //create undirected graph
    unordered_map<int,list<pair<int,int>>>adjc;
    for(int i = 0; i < num_edges; i++)
    {
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        adjc[u].push_back(make_pair(v,w));
        adjc[v].push_back(make_pair(u,w));
    }
    cout<<"DEBUG sec-1"<<endl;
    //requaired Data structure
    vector<int>key(num_node);
    vector<bool>mst(num_node);
    vector<int>parent(num_node);

    //initialize each DS
    for(int i = 0; i <num_node;i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    cout<<"DEBUG sec-2 before prim's: "<<endl;
    //Prims algo starts
    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i <num_node; i++)
    {
        int mini = INT_MAX;
        int u;
        //find minimum node in key
        for(int v = 0; v < num_node; v++)
        {
            // cout<<"DEBUG sec-3 inside find minimum"<<endl;
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        //mark mini node as true
        mst[u] = true;

        //get u adjacent nodes
        for(auto it: adjc[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    for(int i = 0; i < parent.size(); i++)
    {
        cout<<parent[i]<<", ";
    }cout<<endl;
    return 0;
}