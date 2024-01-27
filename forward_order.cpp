#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout << "Enter number for Op:   "<<endl;
    cin >> num;
    int t_num = 0;
    int i = 0;
    while (num != 0)
    {
        int digit = num % 10;
        int power = pow(10,i);
        cout <<" The power is :     "<<power<<"     in iter number : "<<i<<endl;
        t_num = (digit * power) + t_num;
        cout <<"$$$$$$$$$$$$$$$$$$$$$           "<<t_num<<"     &&&&&&&&&&&&&&&"<<endl;
        num = num / 10;
        i++;
    }
    cout << "The Target num Is :    "<<t_num<<endl;
    return 0;
}