#include <iostream>
#include <vector>
using namespace std;


//find element
bool searchElement(vector <vector <int>>&matrix, int target)
{
    //rows and col
    int row = matrix.size();
    int col = matrix[0].size();

    //start, end, mid
    int start  = 0;
    int end = (row * col) - 1;
    int mid = start + (end - start)/2;

    while (start <= end)
    {
        int element = matrix[mid/col][mid%col];

        if (target == element)
        {
            return 1;
        }
        if(target > element)
        {
            start = mid + 1;
        }
        if (target < element)
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2; 
    }
    return 0;
}




int main()
{
    vector<vector<int> > user2D = {{1,2,3},{4,5,6},{7,8,9}};
    cout <<"Check for 3 presence : "<<searchElement(user2D,3)<<endl;
    return 0;
}