#include <iostream>
using namespace std;

int main()
{
    int num ;
    cout <<"Enter number to check whether number is in square of two :";
    cin >> num;
    int count = 0;
    while (num > 0)
    {
        if(num&1)
        {
            count ++;
        }
        num = num >> 1;
    }
    if (count == 1)
    {
        cout << "Number is in the square of 2.......##"<<endl;
    }
    else{
    cout <<"Number is not the square of two"<<endl;}
    return 0;
}