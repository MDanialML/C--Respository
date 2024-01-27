#include <iostream>
using namespace std;

int main()
{
    int n ;
    cout <<"Enter number to check : "<<endl;
    cin >>n;
    if (n & 1)
    {
        cout<<"Number is odd"<<endl;
    }
    else
    cout <<"Number is even "<<endl;
}