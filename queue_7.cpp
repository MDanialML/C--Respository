#include <iostream>
#include <queue>
#include<unordered_map>
using namespace std;

int main()
{
    string my_st = "abbcddefff";
    queue<char> q;
    string ans = "";
    unordered_map<char,int> count;
    //bug encountered
    for(int i =0; i < my_st.length();i++){
        char ch = my_st[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty())
        {
            //check count of current char
            if(count[q.front()] > 1)
            {
                ans.push_back('#');
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                //should be popped out of queue after storing in answer #bug clear
                q.pop();
                break;
            }
        }
        // if(q.empty())
        // {
        //     ans.push_back('#');
        // }
    }
    // for(char ch: my_st)//"abbcddefff"
    // {
    //     count[ch]++;
    //     q.push(ch);
    //     while(!q.empty() && count[q.front()] > 1)
    //     {
    //         q.pop();
    //     }
        
    //     if(q.empty())
    //     {
    //         ans.push_back('#');
    //     }
    //     else
    //     {
    //         ans.push_back(q.front());
    //         //should be popped out of queue after storing in answer #bug clear
    //         q.pop();
    //     }
    // }
    cout<<"Total Non repeating characters: "<<ans<<endl;
    return 0;
}