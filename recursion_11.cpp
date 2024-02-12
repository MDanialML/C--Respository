#include <iostream>
using namespace std;


bool checkPalindrome(string& str, int start)
{
    int end = str.length()-1;
    int mid = 0 + (end - 0)/2;

    //base case
    if (start > mid)
    {
        return true;
    }
    if(str[start] != str[(str.length()-start - 1)])
    {
        return false;
    }
    else
    {
        start++;
        checkPalindrome(str, start); //recursive relation
    }
    

}



int main()
{
    string str = "hello";

    bool isPalindrome = checkPalindrome(str,0);

    if (isPalindrome)
    {
        cout <<"string is a palindrome"<<endl;
    }
    else
    {
        cout <<"string is not a palindrome"<<endl;
    }
    
    return 0;
}