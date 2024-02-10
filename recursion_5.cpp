#include <iostream>
using namespace std;


void callDigits(int num, string arr[])
{
    //base case
    if (num == 0)
    {
        return;
    }

    //precessing
    int digit = num % 10;
    num = num / 10;
    cout <<arr[digit]<<" ";
    callDigits(num,arr);


}


int main()
{
    int num;
    string number[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cout <<"Enter number: "<<endl;
    cin >> num;
    callDigits(num,number);

    return 0;
}