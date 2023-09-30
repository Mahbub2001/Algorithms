#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const long long int INF = 1e18;

class Edge
{
public:
    int a, b;
    long long int w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;

    vector<Edge> v(e);

    for (int i = 0; i < e; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].w;
    }

    int s;
    cin >> s;
    long long int dis[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
    }
    dis[s] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (const Edge &ed : v)
        {
            if (dis[ed.a] != INF && dis[ed.a] + ed.w < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.w;
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int d;
        cin >> d;

        bool cycle = false;
        for (const Edge &ed : v)
        {
            if (dis[ed.a] != INF && dis[ed.a] + ed.w < dis[ed.b])
            {
                cycle = true;
                break;
            }
        }

        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }

        if (dis[d] != INF)
        {
            cout << dis[d] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}


// Problem Statement

// You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

// You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D. You need to tell the minimum cost from source node to destination. If there is no possible path from S to D then print Not Possible.

// Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".


// Sample Input 0

// 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 1
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 0

// 0
// -1
// -2
// -5
// 0
// Sample Input 1

// 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 5
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 1

// Not Possible
// Not Possible
// Not Possible
// Not Possible
// 0
// Sample Input 2

// 5 8
// 1 2 -2
// 1 3 -10
// 3 2 1
// 2 4 7
// 4 3 -3
// 4 5 5
// 2 5 2
// 4 1 1
// 1
// 5
// 1
// 2
// 3
// 4
// 5
// Sample Output 2

// Negative Cycle Detected