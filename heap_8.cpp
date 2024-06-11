//merge k sorted arrays
#include<bits/stdc++.h>
using namespace std;


int main()
{
    //pre requisit
    vector<vector<int>> arr = {{1,2,3,4},{6,7,8},{9,10,11,12,13},{14,15},{16}};
    int row = arr.size();
    cout<<"Total rows: "<<row<<endl;
    for(int i = 0; i<row;i++)
    {
        for(int j = 0; j < arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}