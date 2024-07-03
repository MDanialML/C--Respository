#include <iostream>
#include<vector>
#include<string>
using namespace std;


/*
void longestPrefix(vector<string> wordsVector, string &ans)
{
    for (int i = 0; i < wordsVector[0].length();i++)
    {
        //debuging 
        cout<<"Inside outer loop "<<endl;
        char ch = wordsVector[0][i];
        bool match = true;
        //traversing and comparing rest of string
        for (int j = 1; j < wordsVector.size(); j++)
        {
            //Not match
            if (wordsVector[j].length() < i || wordsVector[j][i] != ch)
            {
                match = false;
                break;
            }
        }
        if(match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
}
*/

//class TrieNode
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    //constructor
    TrieNode(char ch)
    {
        data = ch;
        //initialize children
        for(int i = 0; i < 26;i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    //constructor
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    //insert word into Trie
    void insertUtill(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0 )
        {
            root->isTerminal = true;
            return;
        }
        //assumption for lower case letters
        int index = word[0] - 'a';
        TrieNode* child;
        //if word present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        //recursive call
        insertUtill(child,word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtill(root,word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length();i++)
        {
            char ch = str[i];
            if(root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
    }
};

int main()
{
    Trie* object1 = new Trie('\0');
    vector <string> wordsVector;
    wordsVector.push_back("code");
    wordsVector.push_back("codenz");
    wordsVector.push_back("coding");

    string ans = "";
    for(int i = 0; i < wordsVector.size();i++)
    {
        object1->insertWord(wordsVector[i]);
    }
    cout<<"Insertion Done.!"<<endl;

    // longestPrefix(wordsVector,ans);
    // cout<<"Longest prefix string is: "<<ans<<endl;
    object1->lcp(wordsVector[0],ans);
    cout<<"Longest common prefix is: "<<ans<<endl;


    return 0;
}