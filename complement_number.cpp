    // int bitwiseComplement(int n) {
    //     //edge case
    //     if (n == 0)
    //     {
    //         return 1;
    //     }
    //     int m = n;
    //     int mask = 0;
    //     while (m != 0)
    //     {
    //         mask = (mask << 1) | 1;
    //         m = m >> 1;
            
    //     }
    //     int ans = (~n) & mask;
    //     return ans;
        
    // }

    #include <iostream>
    using namespace std;

    int main()
    {
        int num;
        cout << "Enter number :     "<<endl;
        cin >> num;
        int c_num = num;
        int mask = 0;

        //intial check 
        if (num == 0)
        {
            return 1;
        }

        while (c_num != 0)
        {
            mask = (mask << 1) | 1;
            cout << mask;
            c_num = c_num >> 1;
        }
        int ans = (~num) & mask;
        cout << endl;
        cout << "The final number :     "<< ans;
        return 0;
    }