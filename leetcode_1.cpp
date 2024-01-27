#include <iostream>
using namespace std;

int main(){
    int num;
    cout <<"Enter number : ";
    cin >> num;
    int product = 1;
    int sum = 0;
    while (num > 0)
    {
        int digit = num%10;
        product = product * digit;
        sum = sum + digit;
        num = num / 10;
    }
    int result = product - sum;
    cout << result << endl;
    return 0;
}

//  int count = 0; should be solved on paper
//         while (n != 0){
//             if(n&1){
//                 count ++;
//             }
//            n=  n >> 1;
//         }
//         return count;