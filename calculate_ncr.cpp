#include <iostream>
using namespace std;

//function to calculate factorial
int factorial(int x)
{
    int result = 1;
    for (int i = 1; i <= x;i++)
    {
        result = result * i;
    }
    return result;
}

//function to calculate nCr
int nCr(int n,int r)
{
    int fact_n = factorial(n);
    int fac_r = factorial(r);
    int fact_nr = factorial(n-r);
    int ncr = fact_n/(fac_r*fact_nr);
    return ncr;
}

int main()
{
    int n,r;
    cout <<"Enter the value of n:        ";
    cin >> n;
    cout <<endl;
    cout << "Enter the value of r:      ";
    cin >> r;
    cout <<endl;
    int result = nCr(n,r);
    cout << "nCr of given "<<n<<" and "<<r<<" is:       "<<result<<endl;
    return 0;
}