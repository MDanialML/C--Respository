#include <iostream>
#include <vector>
using namespace std;


//function to reverse an vector

vector<int> reverse(vector<int> v){

    int start = 0;
    int end = v.size() - 1;

    while(start <= end)
    {
        swap(v[start],v[end]);
        start ++;
        end --;
    }

    return v;

}

//print array
void printArray(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout << endl;
    cout << "Printing Done.!"<<endl;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    v.push_back(12);
    v.push_back(14);


    vector<int> ans = reverse(v);

    printArray(ans);
    return 0;
}