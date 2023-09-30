#include <bits/stdc++.h>
using namespace std;

// typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pair<int,int>> graph[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pair vpair : graph[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of a node: " << i << ": ";
        cout << dist[i] << endl;
    }

    return 0;
}

/*
7
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12

*/









// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;

// const int N = 1e5 + 5;
// const int INF = 1e9 + 10;
// vector<pii> graph[N];
// vector<int> dist(N, INF);
// vector<bool> visited(N);

// void dijkstra(int source)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[source] = 0;
//     pq.push({dist[source], source});

//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();

//         visited[u] = true;

//         for (pii vpair : graph[u])
//         {
//             int v = vpair.first;
//             int w = vpair.second;

//             if (visited[v])
//                 continue;

//             if (dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }

// int main()
// {

//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph[u].push_back({v, w});
//         graph[v].push_back({u, w});
//     }
//     dijkstra(1);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Distance of a node: " << i << ": ";
//         cout << dist[i] << endl;
//     }

//     return 0;
// }

// /*
// 7
// 8
// 1 2 3
// 1 3 5
// 3 4 1
// 4 6 1
// 2 5 6
// 5 6 1
// 5 7 2
// 3 7 12

// */
