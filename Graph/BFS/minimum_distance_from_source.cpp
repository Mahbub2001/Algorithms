// Problem Statement

// You will be given an undirected graph as input. You will be given a query Q, for each query you will be given a source S and a destination D. You need to tell the minimum distance from source to destination for each query.

// Note: If there is no path in between the source and destination, print -1.

// Input Format

// First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
// Next E lines will contain A, B which means there is a edge between node A and B.
// Next line will contain Q, the number of queries.
// For each query every line will contain S and D.


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int S, D;
        cin >> S >> D;
        memset(visited, false, sizeof(visited));
        memset(level, 0, sizeof(level));

        bfs(S);
        if (visited[D])
            cout << level[D] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}


// Sample Input 0

// 6 7
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 3 5
// 4 3
// 6
// 0 5
// 1 5
// 2 5
// 2 3
// 1 4
// 0 0
// Sample Output 0

// 2
// 3
// 3
// 2
// 2
// 0
