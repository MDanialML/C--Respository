#include <iostream>
using namespace std;



//row wise sum of 2D array
void rowSum(int arr[][3],int m,int n)
{   int max_row_sum = INT8_MIN;
    for(int row = 0; row < m; row++)
    {
        int row_sum = 0;
        for (int col = 0; col < n; col++)
        {
            row_sum += arr[row][col];
        }
        if(max_row_sum < row_sum)
        {
            max_row_sum = row_sum;
        }
        cout <<"sum of row index : "<<row<<" = "<<row_sum<<endl;
    }
    
    cout <<"Maximum row Sum : "<<max_row_sum <<endl;
}



//column wise sum of 2D array
void colSum(int arr[][3],int m,int n)
{
    int max_col_sum = INT8_MIN;
    for(int col = 0; col < n; col++)
    {
        int col_sum = 0;
        for (int row = 0; row < m;row++)
        {
            col_sum += arr[row][col];
        }
        if(max_col_sum < col_sum){
            max_col_sum = col_sum;
        }
        cout <<"Col sum : "<<col_sum<<" Column number : "<<col <<endl;
    }
    cout <<"Maximum column Sum : "<<max_col_sum<<endl;
}



int main()
{
    int arr[3][3];
    cout << "Enter array element in linear format"<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }
    //row wise sum
    rowSum(arr,3,3);
    //column wise sum
    colSum(arr,3,3);

    return 0;

}