#include <iostream>
using namespace std;

int findPower(int a, int b)
{
    //base case 
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }

    //recursive call
    int ans = findPower(a, b/2);

    if(b&1)
    {
        return a*(ans * ans);
    }
    else
    {
        return ans * ans;
    }
    
}

int main()
{
    int a;
    int b;
    cout <<"Enter the value of a and b:"<<endl;
    cin>> a;
    cin>>b;
    cout<<"power of wrt b is equal to : "<<findPower(a,b)<<endl;

    return 0;
}