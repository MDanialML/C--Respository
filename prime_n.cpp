#include <iostream>
using namespace std;

int isPrime(int n){
    if (n == 1){
        return 0;
    }
    for (int i = 2;i * i <= n;i++){
        if (n % i == 0)
        {
            return 0;
        }
        return 1;
    }   
}

int main(){
    int range_st , range_en;
    int count = 0;
    cout << ("Enter start : ");
    cin >> range_st;
    cout << ("Enter end : ");
    cin >> range_en;
    cout << ("List of prime numbers in given range : ");
    for (int i = range_st ; i <= range_en; i++){
        if (isPrime(i)){
            count = count + 1;
            cout <<i <<" ";
        }
    }
    cout <<endl;
    cout << "Total Count of prime number in given range : "<< count;
    return 0;
}