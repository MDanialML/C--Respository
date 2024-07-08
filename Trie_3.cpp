#include <iostream>
#include<vector>
using namespace std;


//Trie Node
class TrieNode{
    public:
    char data;
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

//class
class Trie{
    public:
    TrieNode* root;
    //constructor
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    //recursive approach 
    void insertUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        //get index of first charactor of given word
        int index = word[0] - 'a';
        //create a new TrieNode
        TrieNode* child;
        //check whether the first charactor of given word is present in the trie
        if(root->children[index] != NULL)
        {
            //move forward means place child pointer on the position where current charactor is present
            child = root->children[index];
        }
        else
        {
            //create new child for current charactor
            child = new TrieNode(word[0]);
            //place new child node on the right children position
            root->children[index] = child;
        }
        //recursive call for inserting next charactor of current word into Trie
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    //function get suggestion

    //function to print suggestion for each prefix 
    void printSuggestion(TrieNode* curr,vector<string>&temp, string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'a'];
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    //this function will do initial processing for
    vector<vector <string>> getSuggestion(string query)
    {
        //pointer to keep trck of previously visited nodes
        TrieNode* prev = root;
        vector<vector<string>> output; 
        //vector to hold suggestion generated using prefix
        string prefix = "";
         //container to hold each prefix from query

        //for looping through each charactor of query string
        for(int i = 0; i<query.length();i++)
        {
            //array to hold suggestion for each prefix in a query
            vector<string> temp;
            //container to keep each char from query
            char lastChar = query[i];
            //now push back lastChar into prefix
            prefix.push_back(lastChar);
            //container to hold next node in Trie
            TrieNode* curr = prev->children[lastChar - 'a'];
            if(curr == NULL)
            {
                break;
            }
            //function to get suggestion for each updated prefix
            printSuggestion(curr,temp,prefix);
            //push suggestion into output vector
            output.push_back(temp);
            //clear temp after each iteration
            temp.clear();
        }
        return output;
    }
};

int main()
{
    Trie* trieStr = new Trie('\0');
    vector<string> wordsVec = {"cod", "coding", "codding", "code", "coly"};
    for(int i = 0; i < wordsVec.size(); i++)
    {
        trieStr->insertWord(wordsVec[i]);
    }

    string query = "cod";
    vector<vector <string>> suggestions = trieStr->getSuggestion(query);

    for(int i = 0; i < suggestions.size(); i++)
    {
        for(int j = 0; j < suggestions[i].size();j++)
        {
            cout<<suggestions[i][j]<<"-";
        }cout<<endl;
    }
    return 0;
}