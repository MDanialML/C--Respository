#include <iostream>
using namespace std;

void reverseString(string& st,int start)
{
    cout<<st<<endl;
    int end = st.length()-1;
    //base case
    if (start > ((0 + end)/2))
    {
        return;
    }

    //processing 
    swap(st[start], st[end - start]);
    start++;

    reverseString(st,start);
}


int main()
{
    string university = "Hazara University Mansehra";
    // string university = "129056";

    reverseString(university,0);

    cout <<university<<endl;

    return 0;
}