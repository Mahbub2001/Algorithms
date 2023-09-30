// You will be given a binary tree as input in level order. You need to print the binary tree in reverse way. Here, reverse way means you need to print from the last level and from left to right.

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
    if (root == NULL)
        return;

    queue<Node *> q;
    stack<int> s;

    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        s.push(f->val);

        if (f->right)
            q.push(f->right);

        if (f->left )
            q.push(f->left);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{

    Node *root = take_input();
    print(root);

    return 0;
}


// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 40 50 60 20 30 10