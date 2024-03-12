#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> ch_stack;
    string str = "(a+(b+c))";
    bool isRedundent = true;
    for (int i = 0; i < str.length();i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            ch_stack.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                while (ch_stack.top() != '(')
                {
                    char top = ch_stack.top();
                    if( top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundent = false;
                        ch_stack.pop();
                    }
                    ch_stack.pop();
                }
                // 
            }
        }
        
    }
    if(ch_stack.empty())
    {
        cout<<"Expression is not redundent"<<endl;
    }
    else
    {
        cout <<"expression is redundent"<<endl;
    }
    

    return 0;
}