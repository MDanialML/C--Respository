#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr,int size,int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);
    int sum = 0;
    //traverse over first k size window
    for(int i =0; i < k;i++)
    {
        /*
        this loop is for removing all the indexes of element that are less than current element 
        of array from deque maxi
        maxi deque only hold the index of maximum element of whole window of size K
        */
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back(); //will pop out index of element, less than current element
        }
        /*
        this loop will remove all the index of element that are greater than current element
        of k size window
        mini deque will only hold the index of minimum of all the element in current K size window of array
        */
        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back(); //pop out index of element which is greater than current current element
        }
        //Now deque maxi is empty and current index is hold the index of max element in K sized window
        //pushing that index into maxi deque
        maxi.push_back(i);
        //Now deque maxi is empty and current index is hold the index of max element in K sized window
        //pushing that index into maxi deque 
        mini.push_back(i);
    }
    //sum hold the value of sum of maximum and minimum element of current processed window
    sum += arr[maxi.front()] + arr[mini.front()];

    //process next windows
    for(int i = k; i<size;i++)
    {
        //remove all the previous index from maxi deque which are not in current  window size
        while(!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        //remove all the previous index from mini deque which are not in current  window size
        while(!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        //this loop will pop all the element index from maxi which are less than current element
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        //this loop will pop all the elements index  from mini que which are greater than current indexed element
        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        //calculate and store the sum maximum and minimum number of current window
        sum += arr[maxi.front()] + arr[mini.front()]; 
    }
    
    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int sum = solve(arr,7,k);
    cout<<"Sum: "<<sum<<endl;
    return 0;
}