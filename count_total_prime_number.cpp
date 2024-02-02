#include <iostream>
#include <vector>
using namespace std;

//count total prime number
//Implemented sieveofEratothenes
int sieveofEratosthenes(int n)
{
    int count = 0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if(prime[i])
        {
            count ++;
            
            for (int  j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
            
        }

    }
    return count;

}


int main()
{
    int n = 100000;

    cout << "Total count of prime number Exist :    "<<sieveofEratosthenes(n)<<endl;
    
    return 0;
}