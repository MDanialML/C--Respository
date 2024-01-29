#include <iostream>
using namespace std;


//remove similar elements
string removeSimilarElements(string str){
    int start = 0;

    while(start < str.length())
    {
        bool removalDone = false;
        if (str[start] == str[start + 1])
        {
            str.erase(start,2);
            removalDone = true;
        }
        if(removalDone){
            start = 0;
        }
        else{
            start++;
        }
    }
    return str;
}


int main()
{
    string str = "abbaca";
    string output = removeSimilarElements(str);
    cout <<"String after dupplicate removed : "<<output<<endl;
    return 0;

}