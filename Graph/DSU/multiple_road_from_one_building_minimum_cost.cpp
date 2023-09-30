#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N = 1e5 + 5;

class Edge {
public:
    int a, b;
    long long int w;
    
    Edge(int a, int b, long long int w) : a(a), b(b), w(w) {}
    
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};

int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    sort(edges.begin(), edges.end());

    long long int total_cost = 0;
    dsu_set(n);

    for (const Edge& edge : edges)
    {
        int a = edge.a, b = edge.b;
        long long int w = edge.w;

        if (dsu_find(a) != dsu_find(b))
        {
            dsu_union(a, b);
            total_cost += w;
        }
    }
    int cmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] == -1)
        {
            cmp++;
        }
    }

    if (cmp == 1)
    {
        cout << total_cost << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}


// Problem Statement

// You have just opened a dish cable business and you want to connect your dish lines in your area. In your area there are N buldings and E roads. The roads are two way obviously. In each road there is a cost of connecting the cables. You want to connect all buldings in such a way that there is connection from any building to another, not necessary to be directly.

// As you are a businessman, you want the total cost to be minimum. Can you tell the minimum total cost to do the work?

// Note: There can be multiple road from one building to another. If it is not possible to connect all the building, print -1.



// Sample Input 0

// 5 7
// 1 2 10
// 1 3 5
// 3 2 4
// 2 4 1
// 3 4 2
// 4 5 3
// 1 5 2
// Sample Output 0

// 8
// Sample Input 1

// 3 2
// 1 2 10
// 2 1 2
// Sample Output 1

// -1