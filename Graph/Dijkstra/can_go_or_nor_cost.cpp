#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void bfs(const vector<vector<pair<long long int,long long int>>> &graph, int S, int d, int dw)
{
    vector<int> dis(graph.size(), INT_MAX);
    priority_queue<pair<long long int, long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int, long long int>>> pq;

    dis[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        long long int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();

        if (d > dis[u])
            continue;

        for (auto eg : graph[u])
        {
            long long int v = eg.first;
            long long int w = eg.second;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    if (dis[d] <= dw)
    {
        cout << "YES"<<endl;
    }
    else
    {
        cout << "NO"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<long long int, long long int>>> graph(N + 1); 
    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    int S;
    cin >> S;

    int T;
    cin >> T;

    while (T--)
    {
        int d, dw;
        cin >> d >> dw;

        bfs(graph, S, d, dw);
    }

    return 0;
}



// Problem Statement

// You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

// You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D and a cost DW. You need to tell if you can go to the destination from source using DW cost.

// Input Format

// First line will contain N and E.
// Next E lines will contain A, B and W.
// Next line will contain source node S.
// Next line will contain T, the number of test cases.
// For each test case, you will get D and DW.

// Sample Input 0

// 5 7
// 1 2 10
// 1 3 2
// 3 2 1
// 2 4 7
// 3 4 2
// 4 5 5
// 2 5 2
// 1
// 5
// 1 0
// 2 5
// 3 1
// 4 4
// 5 6
// Sample Output 0

// YES
// YES
// NO
// YES
// YES