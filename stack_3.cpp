#include<iostream>
#include<stack>
using namespace std;


int main()
{
    string koi_bhi = "Ho gya phir";
    stack<char> st;
    string reverse = "";
    for(int i = 0;i < koi_bhi.length();i++)
    {
        char ch = koi_bhi[i];
        st.push(ch);
    }
    while (!st.empty())
    {
        char ch = st.top();
        reverse.push_back(ch);
        st.pop();
    }
    cout<<reverse<<endl;
    return 0;
}