#include <iostream>
using namespace std;


int power(int num)
{
    //base condition
    if(num == 0)
    {
        return 1;
    }


    //recursive relation
    int smallerProb = power(num - 1);
    int biggerProb = 2 * smallerProb;

    return biggerProb;
}

int main()
{
    int num;
    cout <<"Enter power of: "<<endl;
    cin >> num;

    int ans = power(num);
    cout <<"power of 2: "<<ans<<endl;

    return 0;
}