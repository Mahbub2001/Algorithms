// You will be given a binary tree as input in level order. Also you will be given a level X. You need to print all the node's values in that level from left to right. Assume that level starts from 0.


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *take_input()
{

    int val;
    cin >> val;
    queue<Node *> q;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    if (root)
        q.push(root);

    while (!q.empty())
    {

        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;

        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(l);
        }
        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(r);
        }

        f->left = myLeft;
        f->right = myRight;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
}

void print(Node *root)
{
    int searchLevel;
    cin >> searchLevel;
    bool found = false;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *node = p.first;
        int level = p.second;
        q.pop();

        if (level == searchLevel)
        {
            cout << node->val << " ";
            found = true;
        }

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    if(!found){
        cout<<"Invalid"<<endl;
    }
}

int main()
{

    Node *root = take_input();
    print(root);

    return 0;
}



// Sample Input 0

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 0
// Sample Output 0

// 10
// Sample Input 1

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 1
// Sample Output 1

// 20 30
// Sample Input 2

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 2
// Sample Output 2

// 40 50 60
// Sample Input 3

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 3
// Sample Output 3

// Invalid