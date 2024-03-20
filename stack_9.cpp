#include<iostream>
#include<vector>
#include <stack>
using namespace std;

//next smaller element
vector<int> nextSmallerElement(vector<int> arr,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1;i >= 0;i--)
    {
        int current = arr[i];
        while(s.top() != -1 && arr[s.top()] >= current)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

//previous smaller element
vector<int> previousSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i =0; i < n; i++)
    {
        int current = arr[i];
        while(s.top() != -1 && arr[s.top()] >= current)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> heights,int n)
{
    // vector<int> heights = {2,1,5,6,2,3};
    // int n = heights.size(); //size of array

    //next smaller element array
    vector<int> next(n);
    next = nextSmallerElement(heights,n);

    //previous smaller element array
    vector<int>previous(n);
    previous = previousSmallerElement(heights,n);

    int area = INT8_MIN;
    //loop to calculate max area
    for(int i = 0; i<n;i++)
    {
        int len = heights[i];
        int breadth = next[i] - previous[i] -1;
        if(next[i] == -1)
        {
            next[i] = n;
        }
        int newArea = len * breadth;
        area = max(area,newArea);
    }
    // cout<<"Maximum Area of a Histogram: "<<area<<endl;
    return area;
}

int main()
{
    vector<vector<int>> twoD = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int n = twoD.size();
    int m = twoD[0].size();

    int area = largestRectangleArea(twoD[0],m);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j<m;j++)
        {
            if(twoD[i][j] != 0)
            {
                twoD[i][j] = twoD[i][j] + twoD[i-1][j];
            }
            else
            {
                twoD[i][j] = 0;
            }
            
        }
        area = max(area,largestRectangleArea(twoD[i],m));
    }
    cout <<"Largest area covered by ones is:    "<<area<<endl;
    return 0;
}