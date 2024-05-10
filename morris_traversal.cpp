#include<iostream>
#include<stack>
using namespace std;

//class node 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this-> data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//recusive function to create tree
Node* createTree(Node* root)
{
    cout<<"Enter Data for Node"<<endl;
    int data;
    cin >> data;
    root = new Node(data);
    //base condition
    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter Data for left of "<<data<<endl;
    root -> left = createTree(root -> left);
    cout<<"Enter Data for right of "<<data<<endl;
    root -> right = createTree(root -> right);
}

//inorder Traversal using recurrssion
void printInOrder(Node* root)
{
    //base case 
    if(root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout <<root->data<<"    ";
    printInOrder(root->right);

}

//inorder traceral using stack iterative approach
void inorderStack(Node* root)
{
    Node* current = root;
    stack<Node*> s;

    while(current != NULL || !s.empty())
    {
        //first go to left most of current
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        //here we reached after reaching at left most node of Tree
        //Now we need to print current node data
        current = s.top();
        s.pop();
        cout<<current->data<<"  ";
        //after printing current Node Data we need to go the right chiled
        current = current->right;
    }
}


//Morriss Traversal
void morrissTraceral(Node* root)
{
    //base condition
    if (root == NULL)
    {
        return;
    }
    Node* current = root;
    Node* predecessor;
    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            cout << current -> data<<" ";
            current = current -> right;
        }
        else
        {
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
                }
                if(predecessor->right == NULL)
                {
                    predecessor->right = current;
                    current = current->left;
                }
                else
                {
                    predecessor->right = NULL;
                    cout<<current->data<<" ";
                    current = current->right;
                }
        }
    }
}

//main driver code
int main()
{
    Node* root = NULL;
    root = createTree(root);
    cout<<"Now printing  the tree data using Morriss Traversal"<<endl;
    // printInOrder(root);
    // inorderStack(root);
    morrissTraceral(root);
    return 0;
}