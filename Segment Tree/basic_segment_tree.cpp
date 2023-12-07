#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;

int tree[mx * 3];

void build(int node, int l, int r, int a[])
{
    // cout << node << " " << l << " " << r << endl;
    if (l == r)
    {
        tree[node] = a[r];
        return;
    }
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    build(leftNode, l, mid, a);
    build(rightNode, mid + 1, r, a);

    // value set
    tree[node] = tree[leftNode] + tree[rightNode]; // merge logic can vary by different problems
}

int query(int node, int l, int r, int x, int y)
{
    // puro node bad
    if (r < x || l > y)
    {
        return 0;
    }
    // puro node nebo
    if (l >= x && r <= y)
    {
        return tree[node];
    }
    // majhamajhi obstha. children er upr depend kore
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    return query(leftNode, l, mid, x, y) + query(rightNode, mid + 1, r, x, y);
}

void update(int node, int l, int r, int idx, int val)
{
    if (idx < l || idx > r)
    {
        return;
    }
    if (l == r && l == idx)
    {
        tree[node] = val;
        return;
    }
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    update(leftNode, l, mid, idx, val);
    update(rightNode, mid + 1, r, idx, val);
    tree[node] = tree[leftNode] + tree[rightNode];
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1, a);
    // for (int i = 1; i <= 13; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     x--;
    //     y--;
    //     cout << query(1, 0, n - 1, x, y) << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            int idx, val;
            cin >> idx >> val;
            idx--;
            update(1, 0, n - 1, idx, val);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << query(1, 0, n - 1, x, y) << endl;
        }
    }

    return 0;
}

// 4
// 1 -2 3 4
// 10
// 1 1
// 1 2
// 1 3
// 1 4
// 2 2
// 2 3
// 2 4
// 3 3
// 3 4
// 4 4