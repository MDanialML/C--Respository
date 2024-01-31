#include <iostream>
#include<vector>
using namespace std;

//print in wave form
vector<int> printWave(vector<vector <int>>arr,int nRows,int mCols)
{
    vector <int> resultant; //vector two store wave element
    for(int col = 0; col < mCols; col++)
    {
        if(col&1) //this will true only for odd columns
        {
            for(int row = nRows - 1; row >= 0; row--)
            {
                resultant.push_back(arr[row][col]);
            }
        }
        else
        {
            for (int row = 0; row < nRows; row++)
            {
                resultant.push_back(arr[row][col]);
            }
        }
        
    }

    return resultant;

}


//make 2D array
void pushElement(vector<vector<int>>&arr,int nRows,int mCols)
{
    for(int row = 0; row < nRows; row++)
    {
        vector<int> row_vec;
        for (int col = 0; col < mCols; col ++)
        {   
            cout <<"Enter Value: "<<endl;
            int ele;
            cin >>ele;
            row_vec.push_back(ele);
        }
        arr.push_back(row_vec);
    }
}




int main()
{
    vector<vector<int> > user2D;

    //pushing element to 2d vector
    pushElement(user2D,3,3);

    //wave form
    vector<int> waveElemet = printWave(user2D,3,3);

    for (int element:waveElemet){
        cout <<element<<" ";
    }
    

    return 0;
}