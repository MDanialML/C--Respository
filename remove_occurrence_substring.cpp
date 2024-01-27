#include <iostream>
using namespace std;


//function to remove all occurrence of sub string
string removeSubstring(string str,string sub_str){
    
    while(str.length() != 0 && str.find(sub_str) < str.length())
    {
        str.erase(str.find(sub_str),sub_str.length());
    }
    return str;
}

int main()
{
    string s = "daabcbaabcbc";
    string sub_s = "abc";

    string rem_str = removeSubstring(s,sub_s);
    cout <<"Remaining String : "<< rem_str << endl;
    
    return 0;
}