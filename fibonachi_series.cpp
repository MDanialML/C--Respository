#include <iostream>
using namespace std;


//fibonachi generator
void fibo(int end)
{
    int first = 0;
    int second = 1;
    int next;
    int i = 1;
    while(i <= end)
    {
        cout << first<<" ";
        next = first + second;
        first = second;
        second = next;
        i++;
    }
    cout <<endl;
    
}

int main()
{
    int num;
    cout<<" Enter number terms :  "<<endl;
    cin>> num;
    fibo(num);
    return 0;

}