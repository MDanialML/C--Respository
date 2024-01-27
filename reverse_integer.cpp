#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
    int num;
    cout<< "Input number : "<<endl;
    cin >> num;
    int sum = 0;



    //scenario 1
    //separate and reverse the given digits
    while (num != 0)
    {
        int digit = num % 10;
        //store separated number
        sum = sum * 10 + digit;
        num = num /10;
    }
    cout << "Reversed number is:        "<<sum<<endl;
    return 0;
    
}