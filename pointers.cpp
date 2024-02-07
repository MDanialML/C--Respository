#include <iostream>
using namespace std;

int getSum(int *arr,int n)
{
    int sum = 0;
    for(int i =0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}



/*
//pass by value
void update1(int n)
{
    n++;
}

//pass referenc
void update2(int& n)
{
    n++;
}
*/

int main()
{
    // int i = 10;
    // int *ptr = &i;
    // int **ptr2 = &ptr;
    // ptr++;
    // cout << &i<<endl;
    // cout << ptr<<endl;
    // cout << *ptr2<<endl;
    // cout << i<<endl;
    // cout << *ptr<<endl;
    // cout << **ptr2<<endl;


    // char ch[7] = "abcdef";
    // char *ptr = ch;
    // *ptr++;
    // cout <<*ptr<<endl;
    // cout <<ptr<<endl;


    //reference variables
    /* int i = 5;
    int& j = i; //reference variable refering i
    cout <<i<<endl;
    i++;
    cout <<i<<endl;
    j++;
    cout << i<<endl; 

    int n = 5;
    cout<<"before : " << n<<endl;
    //update, pass by value
    update1(n);
    cout <<"After : " << n<< endl;

    cout<<"Passing by reference"<<endl;
    cout<<"before : " << n<<endl;
    //update, pass by refrence
    update2(n);
    cout <<"After : " << n<< endl;
    */

   int n;
   cin >> n;
   //dynamic size allocatio i.e dynamic memory allocation heap
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int sum = getSum(arr,n);
    cout <<"Sum of dynamic array : "<< sum <<endl;


    return 0;
}
