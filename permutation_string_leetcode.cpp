#include <iostream>
using namespace std;

//check if equal
bool checkEqual(int a[26],int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
        
    }

    return 1;

}



//function to check permutation of string 1 in string s2
bool checkPermutation(string s1, string s2)
{
        //storing count of first string s1
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++ )
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }


    //creating a window of size s1 and traversing over s2 and comparing
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    //store occurrence of 1st window in s2 into a mapping array
    while(i < windowSize && i < s2.length()) //second condition is to check whether s2 is greater than s1 or not
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    //check for equality 
    if (checkEqual(count1,count2))
    {
        return true;
    }

    //further processing
    while(i < s2.length())
    {
        char ch = s2[i]; //extract new character
        int index = ch - 'a';
        count2[index]++;
        char oldchar = s2[i - windowSize];
        index = oldchar - 'a'; //extract old window first character 
        count2[index]--;
        i++;

        //check for equality 
        if (checkEqual(count1,count2))
        {
                return true;
        }

    }
    return 0;



}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout <<"Permutation exist : "<< checkPermutation(s1,s2)<<endl;

    return 0;
}