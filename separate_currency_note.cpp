#include <iostream>
using namespace std;

int main()
{
    int note_100,note_50,note_20,note_1=0;
    int amount ;
    cout << "Enter Amount to count currency notes : "<<endl;
    cin >> amount;

    switch (amount / 100)
    {
    case 0:
        break;
    
    default:
        note_100 = amount / 100;
        amount %= 100;
        break;
    }
    switch (amount/50)
    {
    case 0:
        break;
    
    default:
        note_50 = amount / 50;
        amount %= 50;
        break;
    }
    switch (amount / 20)
    {
    case 0:
        break;
    
    default:
        note_20 = amount / 20;
        amount %= 20;
        break;
    }
    switch (amount/1)
    {
    case 0:
        break;
    
    default:
        note_1 = amount /1;
        break;
    }

    cout <<"Total count of Hundered Note : "<<note_100<<endl;
    cout <<"Total count of Fifty Note : "<<note_50<<endl;
    cout <<"Total count of Twenty Note : "<<note_20<<endl;
    cout <<"Total count of One Note : "<<note_1<<endl;

}