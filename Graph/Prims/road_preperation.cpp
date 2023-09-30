// There are n
//  cities and m
//  roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.

// For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.

// Input

// The first input line has two integers n
//  and m
// : the number of cities and roads. The cities are numbered 1,2,…,n
// .

// Then, there are m
//  lines describing the roads. Each line has three integers a
// , b
//  and c
// : there is a road between cities a
//  and b
// , and its reparation cost is c
// . All roads are two-way roads.

// Every road is between two different cities, and there is at most one road between two cities.

// Output

// Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

// Constraints
// 1≤n≤105

// 1≤m≤2⋅105

// 1≤a,b≤n

// 1≤c≤109

// Example

// Input:
// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4

// Output:
// 14

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N = 1e5 + 5;
typedef pair<int, int> pi;

vector<pi> v[N];
bool vis[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s, int n)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    int count = 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;

        if (vis[b])
            continue;
        vis[b] = true;
        count++;
        edgeList.push_back(parent);
        for (int i = 0; i < v[b].size(); i++)
        {
            pi child = v[b][i];
            if (!vis[child.first])
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgeList.erase(edgeList.begin());
    long long int sw = 0;
    for (Edge val : edgeList)
    {
        sw += (long long)(val.w);
    }
    if (count == n)
    {
        cout << sw << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    prims(1, n);

    return 0;
}

/*

5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

*/