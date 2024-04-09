#include <iostream>
#include <queue>
using namespace std;

//Node implementation
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node (int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* bulidTree(Node* root)
{
    int data;
    cout<<"Enter Data: "<<endl;
    cin >> data;
    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }
    
    //recursively creating child nodes
    cout <<"Enter data for inserting child node the left of:    "<<data<<endl;
    root->left = bulidTree(root->left);
    cout<<"Enter data for inserting child node to right of:     "<<data<<endl;
    root->right = bulidTree(root->right);
    return root;
}

//printing tree data levelOrderTraversal OR breadth first search
void levelOrderTraversal(Node* root)
{
    queue<Node*> q; //queue created to hold nodes
    q.push(root);//root node pushed into queue
    q.push(NULL);//pushed a null value as separator 

    while (!q.empty())
    {
        Node* temp = q.front(); //variable of node type to hold front element of queue
        q.pop(); // pop the front element of queue
        if(temp == NULL) //if temp is holding a null value than its mean level is completed 
        {
            cout<<endl;//prints a line break after the level is completed
            if(!q.empty()) //if queue is holding more nodes its mean we have to push a NULL separator for next level
            {
                q.push(NULL);//NULL separator is pushed at the back of queue for next line break
            }
        }
        else //if queue front is holding a Node other than NULL it mean we have to print out the data of that nodes
        {
            cout<< temp->data<<" "; //prints the data of nodes
            if(temp-> left) // if there is any left child we need push that into queue
            {
                q.push(temp->left);
            }
            if(temp-> right)// if there is rigth child exist than we need to push that child into queue
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node* root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //build tree
    root = bulidTree(root);
    //print tree data
    levelOrderTraversal(root);
    return 0;
}