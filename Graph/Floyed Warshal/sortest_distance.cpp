#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const long long int INF = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<long long int>> v(N + 1, vector<long long int>(N + 1, INF));

    for (int i = 1; i <= N; ++i)
    {
        v[i][i] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int A, B;
        long long int W;
        cin >> A >> B >> W;
        v[A][B] = min(v[A][B], W);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (v[i][k] != INF && v[k][j] != INF)
                {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
    }
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int X, Y;
        cin >> X >> Y;

        if (v[X][Y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << v[X][Y] << endl;
        }
    }

    return 0;
}



// Problem Statement

// You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an edge from A to B which will cost W. Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the destination. You need to print the minimum cost from A to B for each query. If there is no connection between X and Y, print -1.

// Note: There can be multiple edges from one node to another.

// Input Format

// First line will contain N and E.
// Next E lines will contain A, B and W.
// After that you'll get Q.
// Next Q queries will contain X and Y.


// Sample Input 0

// 4 7
// 1 2 10
// 2 3 5
// 3 4 2
// 4 2 3
// 3 1 7
// 2 1 1
// 1 4 4
// 6
// 1 2
// 4 1
// 3 1
// 1 4
// 2 4
// 4 2
// Sample Output 0

// 7
// 4
// 6
// 4
// 5
// 3
// Sample Input 1

// 4 4
// 1 2 4
// 2 3 4
// 3 1 2
// 1 2 10
// 6
// 1 2
// 2 1
// 1 3
// 3 1
// 2 3
// 3 2
// Sample Output 1

// 4
// 6
// 8
// 2
// 4
// 6
