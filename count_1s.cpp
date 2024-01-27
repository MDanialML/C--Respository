#include <iostream>
using namespace std;

int main()
{
    int num ;
    cout << "Enter a binary number :"<<endl;
    cin >> num;
    int count = 0;
    while(num > 0)
    {
        if (num & 1) // & bitwise operator and is used to compare given number bit, to 1 bit
        {
            count ++;
        }
       num = num >> 1; //shifts one bit to right
    }
    cout <<" Number of 1s in the given binary number : "<<count<<endl;
    return 0;
}