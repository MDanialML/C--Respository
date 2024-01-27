#include <iostream>
#include <vector>
using namespace std;

//////// dirty code below //////

int main()
{
    int e_num;
    cout << "Enter number of fibonachi element: ";
    cin >> e_num;
    cout << endl;
    vector<int> ans;

    if (e_num == 0)
    {
        ans.push_back(0);
    }
    if (e_num == 1)
    {
        ans.push_back(0);
        ans.push_back(1);
    }

    int a = 0;
    int b = 1;
    int next;
    ans.push_back(a);
    ans.push_back(1);
    int iter = 2;
    while (iter < e_num){
        next = a + b;
        ans.push_back(next);
        a = b;
        b = next;
        iter ++;

    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<<" ";
    }
    cout << endl;

    return 0;

}