#include <iostream>
using namespace std;

int main()
{
    int ans = 0;
    int arr[7] = {1,1,2,2,3,4,4};
    for (int i = 0; i < 7; i++)
    {
        ans = ans^arr[i];
    }

    cout <<"Unique element is : "<<ans<<endl;
    return 0;
}