#include <iostream>
using namespace std;

//get maximum occurrence of character
char getMaximumChar(string str)
{
    //array 
    int arr[26] = {0};

    //get the array of count
    for (int i = 0; i < str.length();i++)
    {
        //extract character from string
        char ch = str[i];
        int number = 0;//exract relevant position of char for increment
        if(ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else{
            number = ch - 'A';
        }

        //now incrementing the relevant count of number
        arr[number]++;
    }
    //get the maximum count of a charactor
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalchar = 'a' + ans;
    return finalchar;
}

int main()
{
    string str;
    cout <<"Enter string : "<<endl;
    cin >> str;
    cout <<"Maximum occurredstring is : "<<getMaximumChar(str)<<endl;
    return 0;
}