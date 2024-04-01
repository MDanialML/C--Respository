#include <iostream>
#include<stack>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    //check for even size
    if(q.size() % 2 != 0)
    {
        cout<<"Please enter a even Size Queue "<<endl;
        return;
    }
    stack<int> s1;
    int half = q.size() / 2;
    //extract first half of queue and push it to stack
    for(int i = 0; i < half;i++)
    {
        int val = q.front();
        q.pop();
        s1.push(val);
    }
    //now extracting from stack1 and pushing back to stack2 for re ordering
    stack<int> s2;
    while(!s1.empty())
    {
        int val = s1.top();
        s1.pop();
        s2.push(val);
    }

    while(!s2.empty())
    {
        int st_top = s2.top();
        s2.pop();
        int q_front = q.front();
        q.pop();
        q.push(st_top);
        q.push(q_front);
    }
}


int main()
{
    queue<int> que;
    for(int i = 0; i < 10;i++)
    {
        que.push(i + 11);
    }
    interLeaveQueue(que);
    cout<<">>!!     AFTER INTERLEAVING FIRST HALF WITH SECOND HALF      !!<<"<<endl;
    while(!que.empty())
    {
        cout<<" "<<que.front();
        que.pop();
    }
    
    return 0;
}