#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main()
{
    int arr[5] = {2,4,1,3,5};
    int n = 5;
    stack<int> s;
    s.push(-1);
    vector<int> ans(5);

    for(int i = n-1; i >= 0;i--)
    {
        int current = arr[i];
        while(s.top() >= current)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(current);
    }
    
    for(int i = 0;i < ans.size();i++)
    {
        cout << ans[i]<<",";
    }cout<<endl;

    return 0;
}
