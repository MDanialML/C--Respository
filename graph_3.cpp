#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

//check for cycle existance in given directed graph
bool checkCycleDFS(int node,unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited,unordered_map<int, list<int>> &adjc)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto neighbour: adjc[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited,adjc);
            if(cycleDetected)
            {
                return true;
            }
            else if(dfsVisited[neighbour])
            {
                return true;
            }
        }
    }
    dfsVisited[node] = false;
}

int main()
{
    int number_of_edges;
    int number_of_nodes;
    cout<<"Enter number of Nodes:"<<endl;
    cin>>number_of_nodes;
    cout<<"Enter number of Edges: "<<endl;
    cin>> number_of_edges;
    unordered_map<int, list<int>> adjc;
    cout<<"Enter each edges in the form pair"<<endl;
    for (int i = 0; i< number_of_edges; i++){
        int u,v;
        cin>>u;
        cin>>v;
        adjc[u].push_back(v);
    }
    cout<<"Directed graph is successfully created: "<<endl;
    cout <<"No printing directed graph parent node and their adjacent child node: "<<endl;
    for(auto i : adjc)
    {
        cout<<i.first<<"->";
        for(auto j : i.second)
        {
            cout<<j<<",";
        }cout<<endl;
    }
    //check for cycle in directed graph
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    bool cycleFound;
    cycleFound = checkCycleDFS(1,visited,dfsVisited,adjc);
    if(cycleFound)
    {
        cout<<"Cycle found in the given directed graph"<<endl;
    }
    else
    {
        cout<<"Cycle doesn't exist"<<endl;
    }

    return 0;
}