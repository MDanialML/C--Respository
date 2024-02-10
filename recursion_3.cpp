#include <iostream>
using namespace std;

void print(int num)
{
    //base condition
    if(num == 0)
    {
        return;
    }
    print(num - 1); //recursive function used before processing called head recursion
    cout <<num <<" ";
    //recursive relation 
    //print(num - 1); //recusive relation is used after processing called tail recursion
}


int main()
{
    int num;
    cout <<"Enter number: "<<endl;
    cin >> num;
    print(num);


    return 0;
}