#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;
    int k = 5;
    for(int i = 0;i < 10; i++)
    {
        q.push(i);
    }

    //reverse element in k size window
    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    //re arranging relative position of queue
    for(int i =0; i < (q.size() - k); i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    while(!q.empty())
    {
        cout<<": "<<q.front();
        q.pop();
    }

    return 0;
}