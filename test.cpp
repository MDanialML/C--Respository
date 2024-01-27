#include <iostream>
using namespace std;

//find length of an array
int length(char name[])
{
     int count = 0;
    for (int i = 0; name[i] != '\0';i++)
    {
        count++;

    }
    return count;
}
//reverse string
void reverseIt(char name[])
{
    int len = length(name);

    int start = 0;
    int end = len -1;
    while(start < end)
    {
        swap(name[start],name[end]);
        start++;
        end--;
    }

}


int main()
{
    // int num = 1330;
    // int f_hundered = 100;
    // cout << num / f_hundered;

    char name[20];
    cin >>name;
    reverseIt(name);
   
    cout <<"Reversed name is  : "<<name<<endl;
    return 0;
}