#include <iostream>
#include <vector>
using namespace std;

//spiral element extraction
vector<int> spiralPrint(vector<vector <int>>& matrix)
{
    //vector to store spiral element 
    vector<int> spiralElement;
    //get dimension of vector
    int totalRows = matrix.size();
    int totalCols = matrix[0].size();

    //initialize count and total count
    int count = 0;
    int totalCount = totalRows * totalCols;

    //initialize indexes
    int rowStart = 0;
    int colStart = 0;
    int rowEnd = totalRows - 1;
    int colEnd = totalCols - 1;

    //traverse all vector element
    while (count < totalCount)
    {
        //first row
        for (int index = colStart; index <= colEnd; index++)
        {
            spiralElement.push_back(matrix[rowStart][index]);
            count ++;
        }
        rowStart++; //shift startRow to next row


        //last column
        for (int index = rowStart; index <= colEnd; index++)
        {
            spiralElement.push_back(matrix[index][colEnd]);
            count++;
        }
        colEnd--; //shift column end to second last column

        //last row
        for (int index = colEnd; index >= colStart; index--)
        {
            spiralElement.push_back(matrix[rowEnd][index]);
            count++;
        }
        rowEnd--; //shift rowEnd to second last row

        //first column
        for (int index = rowEnd; index >= rowStart; index--)
        {
            spiralElement.push_back(matrix[colStart][index]);
            count++;
        }
        colStart++; //shift start column to second column

    }
    return spiralElement;
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

    //spiral elements
    vector<int> spiralElement = spiralPrint(user2D);

    for (int element:spiralElement){
        cout <<element<<" ";
    }
    

    return 0;
}