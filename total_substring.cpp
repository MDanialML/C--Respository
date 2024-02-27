#include <iostream>
using namespace std;

int main()
{
    string str;
    cout <<"Input any string: "<<endl;
    cin >> str;
    int len = str.length();
    for (int i =0; i < len;i++)
    {
        string temp = "";
        for(int j =i; j<len;j++)
        {
            temp.push_back(str[j]);
            cout << temp<<endl;
        }
    }

    return 0;
}