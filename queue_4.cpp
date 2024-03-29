#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue <int> q;
    stack<int> s;

    for(int i =0; i<10; i++)
    {
        q.push(i);
    }
    while(!q.empty())
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
    while(!q.empty())
    {
        cout<<q.front()<<" : ";
        q.pop();
    }

    return 0;
}