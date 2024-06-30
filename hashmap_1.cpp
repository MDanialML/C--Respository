#include<iostream>
#include<map>
#include <unordered_map>
using namespace std;


int main()
{
    unordered_map<string,int> my_map;
    //insertion 1st method
    pair<string,int> pair1 = make_pair("danial",1);
    my_map.insert(pair1);
    //method 2
    pair<string,int> pair2("Arif",2);
    my_map.insert(pair2);
    //update 
    my_map["Arif"] = 3;
    for (auto i:my_map)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    //check for absence or presence
    cout<<my_map.count("danial")<<endl;
    // cout<<my_map.at("ramshu")<<endl; //throwing exception index out of bound
    cout << my_map["ramshu"]<<endl;
    cout<<my_map.at("ramshu")<<endl;
    return 0;
}
