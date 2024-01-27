#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number to check : ";
    cin >> n;
    int isPrime = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // cout << n <<"   is Not prime"<<endl;
            isPrime = 0;
            break;
        }
        else
        {
            // cout <<n << "   Is a prime number"<<endl;
            isPrime = 1;
        }
    }
    if (isPrime == 1)
    {
        cout << n<<"    is prime"<<endl;
    }
    else
    {
        cout <<n << "   is Not prime"<< endl;
    }
    return 0;
}