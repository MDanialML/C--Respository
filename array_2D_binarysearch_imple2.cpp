#include <iostream>
#include <vector>
using namespace std;


//search target element
bool searchElement(vector<vector <int>>& matrix,int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int startRow = 0;
    int endCol = col -1;

    while(startRow < row && endCol >= 0)
    {
        int element = matrix[startRow][endCol];

        if (element == target)
        {
            return 1;
        }
        if (target > element)
        {
            startRow++;
        }
        if (target < element)
        {
            endCol--;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 17;

    cout <<"Element Found : "<<searchElement(matrix,target);

    return 0;
}