#include <iostream>
using namespace std;

int fact(int num){
    if (num == 0 || num == 1){

        return 1;
    }
    else 
    return num * fact(num - 1);
}

int main(){
int f_num, result;
cout << ("Enter number ");
cin >> f_num;
if (f_num < 0){
    cout << ("To find a factorial number should be greater than zero");
}
else {
result = fact(f_num);
cout << ("factorial of given Number Is : ",result);
}
return 0;
}