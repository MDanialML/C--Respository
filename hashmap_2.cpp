#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

#define END return 0;

pair<int,int> freqOfOccurrence(int arr[],int len)
{
    int max_freq = INT8_MIN;
    pair<int,int> ele_with_max_freq;
    unordered_map<int,int> freq_map;
    for (int i = 0; i< len;i++)
    {
        freq_map[arr[i]]++;
    }
    for(auto i : freq_map)
    {
        if(i.second > max_freq)
        {
            max_freq = max(max_freq, i.second);
            ele_with_max_freq = make_pair(i.first,max_freq);
        }
    }
    /*
    for(auto i: freq_map)
    {
        if(i.second == max_freq)
        {
            ele_with_max_freq = make_pair(i.first,i.second);
        }
    }
    */
    return ele_with_max_freq;
}

int main()
{
    int arr[] = {1, 3, 2, 5, 1, 3, 5, 9, 2, 4, 3, 5, 2, 1, 5, 3, 4, 2, 7, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    pair<int,int> max_occurring_freq = freqOfOccurrence(arr,len);
    cout<<"Maximum occuring frequency of: "<<max_occurring_freq.first<<"-"<<max_occurring_freq.second<<endl;
    END
}