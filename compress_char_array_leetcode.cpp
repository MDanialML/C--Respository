#include <iostream>
#include <string>
#include <vector>
using namespace std;


//char compressor
int stringCompressor(vector<char>&chars)
{
    int i = 0;
    int ansIndex = 0;
    int len = chars.size();

    while(i < len)
    {
        int j = i + 1; //pick next element
        while (j < len && chars[i] == chars[j])
        {
            j++;
        }

        //store old char
        chars[ansIndex++] = chars[i];

        //count of occurrence of current element
        int count = j - i;

        if(count > 1)
        {
            string c_count = to_string(count);
            for(char ch:c_count){
                chars[ansIndex++] = ch;
            }
        }
        i = j; //next array element
    }
    return ansIndex;
}


int main()
{
    vector <char> chars = {'a','a','b','b','c','c','c'};

    int count = stringCompressor(chars);

    cout << "size of resultant string" << count<<endl;

    // for (int i = 0; i < chars.size(); i++)
    // {
    //     cout << chars[i]<<" ";
    // }
    return 0;
}