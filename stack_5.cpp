#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string braces = "{{{{{}";
    stack<char> s;
    if(braces.length() % 2 == 1)
    {
        cout<<"Invalid pair"<<endl;
    }
    for (int i =0; i <braces.length();i++)
    {
        char ch = braces[i];
        if(ch == '{')
        {
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
    // //print stack data
    // while(!s.empty())
    // {
    //     cout<<s.top
    // }

    int a =0,b=0;
    while(!s.empty())
    {
        if(s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    cout<<"Number of reversal requaired "<<ans<<endl;
    return 0;
}