#include <iostream>
#include <vector>
using namespace std;

void generateSeq(string digits, string output, int index, string *mapping,vector<string>&ans)
{
    //base case
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    //extract number from digit string
    int number = digits[index] - '0';
    //get string 
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        //recursive call
        generateSeq(digits,output,index+1,mapping,ans);
        //remove last entry from output string
        output.pop_back();
    }
}



int main()
{
    string digits = "69";
    int index = 0;
    vector<string> ans;
    string output = "";
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    generateSeq(digits,output,index,mapping,ans);
    
    //print elements of ans vector
    for(int i = 0; i < ans.size();i++)
    {
        cout<<ans[i]<<",";
    }cout <<endl;
    return 0;
}
