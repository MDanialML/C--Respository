#include <iostream>
using namespace std;


int fibo(int num)
{

    //base case
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    cout <<num<<" ";
    
    //recursive relation
    int series = fibo(num - 1) + fibo(num - 2);

    return series ;

}


int main()
{
    int nth_term;
    cout <<"Enter nth term to get fibonachi series: "<<endl;
    cin >> nth_term;

    cout <<fibo(nth_term);

    return 0;
}