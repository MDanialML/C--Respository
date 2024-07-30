#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<limits.h>
using namespace std;


int main()
{
    //create adjacency list
    unordered_map<int,list<pair<int,int>>> ajdc;
    int num_edges;
    cout<<"Enter Number of Edges: "<<endl;
    cin>>num_edges;
    int num_node;
    cout<<"Enter number of Nodes: "<<endl;
    cin>>num_node;
    cout<<"Enter Egde and their respective weight like(1,3,5)"<<endl;
    for(int i = 0; i < num_edges; i++)
    {
        int u,v,w;
        cin>>u;
        cin>> v;
        cin>> w;
        ajdc[u].push_back(make_pair(v,w));
        ajdc[v].push_back(make_pair(u,w));
    }
    //create a vector to hold distances between edges
    vector<int> dist(num_node);
    //initial each edge distance with infinity
    for(int i =0; i < num_node; i++)
    {
        dist[i] = INT_MAX;
    }
    //create a set to hold a pair of (distance,node)
    set<pair<int,int>> st;
    //source node from where we need distance to each node
    int source = 0;
    //mark source node distance 
    dist[source] = 0;
    //insert source node and their correspondance distance into set
    st.insert(make_pair(0,source));

    //now traverse all adjacent node of source node
    while (!st.empty())
    {
        //fetch top node
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top from set 
        st.erase(st.begin());
        //traverse over neighbour 
        for(auto neighbour : ajdc[topNode])
        {
            //update distance
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                //before updating distance check for entry of current neighbour in set
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if(record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //now update set with new distance and node
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    //now print shortest distance vector
    for( int i = 0; i < dist.size(); i++)
    {
        cout<<dist[i]<<",";
    }cout<<endl;
    return 0;
}