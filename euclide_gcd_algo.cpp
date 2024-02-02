#include <iostream>
using namespace std;


//gcd calculator
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if(b == 0)
    {
        return a;
    }
    while (a != b)
    {
            if (a > b)
        {
            a = a - b;
        }
        if (b > a)
        {
            b = b - a;
        }

    }
    return a;
}

int main()
{
    int a = 1071;
    int b = 462;

    cout << "Greatest common divisor of 1071 and 462 is : "<<gcd(a,b)<<endl;
    return 0;
}