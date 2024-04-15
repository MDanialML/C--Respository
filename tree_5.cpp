#include <iostream>
#include <queue>
using namespace std;

//Node
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//Building tree using iterative + level order approach
Node* buildBinaryTree(Node* root)
{
    cout <<"Enter Maximum Height of Tree:   ";
    int height;
    queue<Node*> q;
    cin >> height;
    if(height >= 1)
    {
        cout <<"Enter Data for root Node:   ";
        int d;
        cin >>d;
        Node* root = new Node(d);
        q.push(root);
        int levelCount = 1;
        cout<<"Level one Completed.!"<<endl;
        while(!q.empty() && levelCount <= (height*2))
        {
            Node* temp = q.front();
            q.pop();
            cout<<"Enter Data for left of:   "<<temp->data<<endl;
            int value;
            cin >>value;
            temp->left = new Node(value);
            q.push(temp->left);
            cout<<"Enter Data for right of: " <<temp->data<<endl;
            cin>>value;
            temp->right = new Node(value);
            q.push(temp->right);
            levelCount++;
        }
    }
    return root;
}

int main()
{
    Node* root = NULL;
    root = buildBinaryTree(root);
    return 0;
}


//chat gpt response
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* buildBinaryTreeIterativeLevelOrder(const std::vector<int>& data) {
    if (data.empty()) {
        return nullptr; // Empty tree
    }

    Node* root = new Node(data[0]);
    std::queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < data.size()) {
        Node* current = q.front();
        q.pop();

        // Create left child if data exists
        if (i < data.size()) {
            current->left = new Node(data[i]);
            q.push(current->left);
        }
        i++;

        // Create right child if data exists
        if (i < data.size()) {
            current->right = new Node(data[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}
