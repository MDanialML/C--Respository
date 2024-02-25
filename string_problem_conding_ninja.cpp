#include <iostream>
using namespace std;

//function to extract digits and then add
void addString(string num_1,string num_2,string &result)
{
    int carry = 0;
    int i = num_1.length() - 1;
    int j = num_2.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        // cout<<"Inside function while"<<endl;
        int digit_1 = (i >= 0)? num_1[i] - '0':0;
        int digit_2 = (j >= 0)? num_2[j] - '0':0;
        int sum = digit_1 + digit_2 + carry;
        int resul_digit = sum % 10;
        char res = '0' + resul_digit;
        // cout<<res<<endl;
        carry = sum / 10;
        result = result + res;
        i--;
        j--;
    }

}

//reverse string
void reverse(string &result)
{
    int i = 0;
    int j = result.length()-1;
    while (i < j)
    {
        swap(result[i],result[j]);
        i++;
        j--;
    }
    
}

int main()
{
    string num_1 = "26";
    string num_2 = "99";
    string result = "";
    //function call
    addString(num_1,num_2,result);
    reverse(result);
    cout <<"Sum of digits in string is: "<<result<<endl;
    return 0;
}