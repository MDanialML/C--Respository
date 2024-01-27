#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout <<"Enter number for conversion :   "<<endl;
    cin>>num;
    int i = 0,t_num = 0;

    while (num != 0)
    {
        int digit = num % 10;
        if (digit == 1)
        {
            t_num = t_num + pow(2,i);
        }
        i++;
        num = num / 10;
    }
    cout <<"The equivalent number is :  "<<t_num<<endl;
    return 0;
}
