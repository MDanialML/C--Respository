#include<iostream>
#include<queue>
using namespace std;

//class Node
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//insert into bst
Node* insertIntoBST(Node* root,int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if(root->data > d)
    {
        root->left = insertIntoBST(root->left,d);
    }
    else
    {
        root->right = insertIntoBST(root->right,d);
    }
}

//takeInput
void takeInput(Node* &root)
{
    int data;
    cin>> data;
    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}


void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<"     "<<temp->data;
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

pair<int,int> findInorderPandS(Node* root, int key)
{
    Node* temp = root;
    int pred = -1;
    int succ = -1;
    while (temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    //Now reached at target key
    //pred && succ

    //pred maximum number in left subtree
    Node* leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    //succ minimum number in right subtree
    Node* rightTree = temp->right;
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    //return answer
    pair<int,int> ans = make_pair(pred,succ);
    return ans;

}


int main()
{
    Node* root = NULL;
    cout<<"Enter data for BST Node"<<endl;
    takeInput(root);
    cout<<"Level Order Traversal Traversal"<<endl;
    levelOrderTraversal(root);

    //pred and succ in given BST
    cout<<"Get predcessor and successor in current BST"<<endl;
    int key;
    cout<<"Enter key to get Predcessor and successor from given BST"<<endl;
    cin>>key;
    pair<int,int> output = findInorderPandS(root,key);
    cout<<"Predecessor of given key is:   "<<output.first<<"    Successor of given key is:      "<<output.second<<endl;
    return 0;
}