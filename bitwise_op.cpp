#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 7;
    cout <<"a & b : "<<(a&b)<<endl;
    cout <<"a | b : "<<(a|b)<<endl;
    cout <<"Not a : "<<(~a)<<endl;
    cout <<"a ^ b : "<<(a^b)<<endl;

    //left shift op
    int c = b << 1;
    cout << c << endl;

    //right shift 
    int r = b >> 1;
    cout << r << endl;


    return 0;
}