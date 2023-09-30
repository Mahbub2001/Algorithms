// You will be given a binary tree as input in level order. You need to give the maximum and minimum values of all the leaf nodes available.

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

void get_min_max(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    int max_num = INT_MIN, min_num = INT_MAX;

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        if (f->left == NULL && f->right == NULL)
        {
            max_num = max(f->val, max_num);
            min_num = min(f->val, min_num);
        }

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    cout << max_num << " " << min_num << endl;
}

int main()
{

    Node *root = take_input();
    get_min_max(root);

    return 0;
}
