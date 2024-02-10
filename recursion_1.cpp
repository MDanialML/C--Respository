//for recursion we need a base case and recursive relation
#include <iostream>
using namespace std;

int factorial(int num)
{
    if(num == 0)
    {
        return 1;
    }

    int smallerProb = factorial(num - 1);
    int biggerProb = num * smallerProb;

    return biggerProb;

}


int main()
{
    int num;
    cout<<"Enter Number: "<<endl;
    cin >> num;

    int ans = factorial(num);
    cout <<"Factorial of given number is: "<<ans<<endl;

    return 0;
}
