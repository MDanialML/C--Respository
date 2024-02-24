#include <iostream>
#include <cctype>
using namespace std;

//convert first letter to uppercase
void convertToUpper(string &mystr)
{
    for(int i = 0; i < mystr.length();i++)
    {
        if( i == 0)
        {
            if (mystr[i] >= 'a' && mystr[i] <= 'z')
            {
                mystr[i] = mystr[i] - ('a' - 'A');
            }
        }
    else if(mystr[i] == ' ')
        {
            if (mystr[i+1] >= 'a' && mystr[i+1] <= 'z')
            {
                mystr[i+1] = mystr[i+1] - ('a' - 'A');
            }
        }
    }
}

int main()
{
    string mystr = "i am a student of the third year";

    convertToUpper(mystr);
    cout<< mystr<<endl;

    return 0;
}
