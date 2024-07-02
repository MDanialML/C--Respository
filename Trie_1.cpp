#include <iostream>
#include<string>
using namespace std;

// trie node
class TrieNode{
    public:
    int data;
    TrieNode* children[26];
    bool isTerminal;

    //constructor
    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

//Trie class
class Trie{
    public:
    TrieNode* root;

    //constructor
    Trie()
    {
        root = new TrieNode('\0');
    }

    //recursive for insertion
    void insertUtill(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            cout<<"base case time"<<endl;
            return;
        }
    //assumption word has all caps charactors
        int index = word[0] - 'A';
        TrieNode* child;

        //if char already present
        if(root->children[index] != NULL){
            child = root->children[index];
            cout<<"Present time"<<endl;
        }
        else
        {
            //for absent
            cout<<"Absent Time"<<endl;
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursive call for rest char
        return insertUtill(child,word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtill(root,word);
    }
//function for search word in a Trie
    bool searchUtil(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }
        
        int index = word[0] - 'A';
        TrieNode* child;
        //present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            //absent
            return false;
        }
        //recursive call
        searchUtil(child,word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }
};


int main()
{
    cout <<boolalpha; //for printing true or false without this search function result is 240 which is ASCII value of non printable charactors
    Trie* obj1 = new Trie();
    obj1->insertWord("ABCD");
    cout<<endl;
    cout<<endl;
    obj1->insertWord("DANIAL");
    cout<<endl;
    cout<<endl;
    obj1->insertWord("DANIAL");
    cout<<"Present or Not:  "<<obj1->searchWord("TIM")<<endl;
    return 0;
}