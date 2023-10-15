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

Node *input()
{
    queue<Node *> q;
    int val;
    cin >> val;
    Node *root;
    if (val != -1)
    {
        root = new Node(val);
    }
    else
    {
        root = NULL;
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
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

void insert(Node *&root, int x)
{

    if (root == NULL)
    {
        root = new Node(x);
        return;
    }

    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}

Node *convert_bst(int a[], int n, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);

    Node *leftRoot = convert_bst(a, n, l, mid - 1);
    Node *rightRoot = convert_bst(a, n, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

int main()
{
    // Node *root = input();
    // print(root);
    // int x;
    // cin >> x;
    // bool get = search(root, x);

    // if (get)
    //     cout << "Found" << endl;
    // else
    //     cout << "Not Found" << endl;

    // int x;
    // cin >> x;
    // insert(root, x);
    // print(root);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);

    Node *root = convert_bst(a, n, 0, n - 1);
    print(root);

    return 0;
}

// 10 5 15 2 6 12 16 -1 3 -1 -1 -1 -1 -1 -1 -1 -1
// 20 10 30 -1 15 25 35 -1 -1 -1 -1 -1 -1