#include <iostream>
#include <math.h>
using namespace std;

// int main()
// {
//     int num;
//     cout << "Enter number to convert from decimal to binary :   ";
//     cin >> num;
//     cout << endl;
//     while (num > 0)
//     {
//         cout << num % 2;
//         num = num /2;
//     }
//     cout << endl;
//     cout << "Convergin completed "<<endl;
// }

//now same problem with different approach solved with different appraoch that is by right shift op

int main()
{
    int num;
    cout << "Enter number for conversion:   "<<endl;
    cin >> num;
    int answer = 0 ;
    int i = 0;
    while (num != 0)
    {
        int digit = num & 1;
        answer = (digit * pow(10, i) ) + answer;
        //answer = answer + (digit << i); 
        num = num >> 1;
        i++;
    }
    cout << "Digit in reverse order are :   "<<answer<<endl;
    return 0;
}