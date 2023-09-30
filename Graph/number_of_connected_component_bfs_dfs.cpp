#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool visited[N];
int level[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
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
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> v >> u;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        // dfs(i);
        bfs(i);
        cc++;
    }
    cout << "Number of connected components: " << cc << endl;

    return 0;
}

/*

7
5
1 2
1 3
2 3
2 4
5 6

*/