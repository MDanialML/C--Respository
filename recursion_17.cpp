#include <iostream>
#include <vector>
using namespace std;

void substrings(string str, string output, int index, vector<string>&ans)
{
    if(index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    //exclude
    substrings(str,output,index+1,ans);

    //include
    char ch = str[index];
    output.push_back(ch);
    substrings(str,output,index+1,ans);
}


int main()
{
    string str = "abc";
    string output = "";
    vector<string> ans;
    int index = 0;

    substrings(str, output, index, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"-";
    }

    return 0;
}