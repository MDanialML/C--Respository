// #include <iostream>
// using namespace std;

// //to lower case
// char toLowerCase(char ch)
// {
//     if (ch >= 'a' && ch <= 'z')
//     {
//         return ch;
//     }
//     else{
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }
// }

// //check palindrome
// bool checkPalindrom(char ch[],int size)
// {
//     int start = 0;
//     int end = size - 1;
//     bool cond ;
//    while (start <= end)
//    {
//      //check for non alphanumeric characters
//     if (!(ch[start] >= 'a' && ch[start] <= 'z') || !(ch[start] >= 'Z' && ch[start] <= 'Z') || !(ch[start] >= '0' && ch[start] <= '9'))
//     {
//         start++;
//     }
//     else if (!(ch[end] >= 'a' && ch[end] <= 'z') || !(ch[end] >= 'Z' && ch[end] <= 'Z') || !(ch[end] >= '0' && ch[end] <= '9'))
//     {
//         end--;
//     }
//     else{
//         //to lower case
//         if (ch[start] >= 'A' && ch[start] <= 'Z')
//         {
//            ch[start] = toLowerCase(ch[start]);
            
//         }
//         if ( (ch[end] >= 'A' && ch[end] <= 'Z'))
//         {
//             ch[end] = toLowerCase(ch[end]);
//         }
        


//         if(ch[start] != ch[end])
//         {
//             cond = false;
//             break;

//         }
//         else
//         {
//             start++;
//             end--;
//         }
//     }
//    }
//    return cond;
// }

// int main()
// {
//     int maxSize = 100;
//     char ch[100];
//     cout<<"Enter sequence of string to Check : "<<endl;
//     cin.getline(ch,17);

//     cout <<"Given string is palindrom :     " << checkPalindrom(ch,17)<< endl;

//     return 0;
// }
// #include <iostream>
// #include <string>
// using  namespace std;


//filter out alphanumeric characters from string




//convert to lower case


//valid palindrome or not