#include <iostream>
using namespace std;

//convert to lower case
char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    
}


//check palindrom
bool checkPalindrom(char name[], int len)
{
    int start = 0;
    int end = len - 1;

    while(start <= end)
    {
        if (toLowerCase(name[start]) != toLowerCase(name[end]))
        {
            return 0;
        }
        else
        {
            start++;
            end--;
            return 1;
        }
    }
}

//function to reverse char array
void reverseName(char name[],int len)
{
    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        swap(name[start++], name[end--]);
    }
}

//function to get length
int charLen(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {count ++; }

    return count;
}

int main()
{
    char name[20];
    cout <<"Enter your Name: ";
    cin >> name;
    cout << endl;

    //function call
    int len = charLen(name);
    reverseName(name,len);

    cout << "Your reversed Name is : " << name<<endl;
    cout <<"Is it palindrome : "<< checkPalindrom(name,len);

    return 0;
}