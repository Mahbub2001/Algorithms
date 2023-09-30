// You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

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
    int fullLevel = 0, count = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *node = p.first;
        int level = p.second;
        q.pop();

        fullLevel = level;
        count++;

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    if (count == ((pow(2,fullLevel)) - 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{

    Node *root = take_input();
    print(root);

    return 0;
}



// Sample Input 0

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output 0

// YES
// Sample Input 1

// 10 20 30 40 -1 60 -1 -1 -1 -1 -1
// Sample Output 1

// NO
// Sample Input 2

// 10 20 -1 -1 -1
// Sample Output 2

// NO
// Sample Input 3

// 10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output 3

// YES
