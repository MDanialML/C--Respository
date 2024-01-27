#include <iostream>
using namespace std;

int main()
{
    int num ;
    cout << "Enter the number to separate their digit : "<<endl;
    cin >> num;
    int count = 0;
    while (num > 0)
    {
        int digit = num % 10;
        cout << "The digit at position: "<<count <<"from right to left Is : ";
        cout<<digit <<endl;
        num = num / 10;
    }
    return 0;
}