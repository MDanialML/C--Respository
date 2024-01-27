#include <iostream>
using namespace std;

//Arithmetic progression calculator
int calAp(int st,int lst, int c_diff)
{
    int nth_term = st + ((lst-1) * c_diff);
    return nth_term;
}


int main()
{
    int st,lst,common_diff;
    cout << "   Enter start of AP :     ";
    cin >> st;
    cout <<endl;
    cout <<"    Enter last term :   ";
    cin >>lst;
    cout <<endl;
    cout <<"    Enter common difference :       ";
    cin >> common_diff;
    cout <<endl;
    int calculated_num = calAp(st,lst,common_diff);
    cout << "AP of given Term is :      "<<calculated_num;
    return 0;
}