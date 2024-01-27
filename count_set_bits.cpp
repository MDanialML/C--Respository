#include <iostream>
using namespace std;

//extract set bits
int setBits(int a,int b)
{
    int count = 0;

    while (a != 0)
    {
        if (a & 1){
            count = count + 1;
        }
        a = a >> 1;
    }
    while (b != 0)
    {
        if (b & 1)
        {
            count = count + 1;
        }
        b = b >> 1;
    }
    return count;

}

int main()
{
    int num_1, num_2;
    cout <<"    Enter first number :    ";
    cin >> num_1;
    cout << endl;
    cout << "   Enter second number : ";
    cin >> num_2;
    cout <<endl;
    int count = setBits(num_1,num_2);
    
    cout << "Total number of set bit in given two numbers are :"<<count<<endl;
    return 0;
    
}