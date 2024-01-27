#include <iostream>
using namespace std;

//convert to lower case
char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main()
{
    char ch;
    cout << "Enter any character : "<<endl;
    cin >> ch;
    cout <<"Given character is : "<<toLowerCase(ch)<<endl;
    return 0;
}