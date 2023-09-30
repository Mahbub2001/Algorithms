#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool visited[N];
int level[N];

bool dfs(int u, int p = -1)
{
    bool cycleExist = false;
    visited[u] = true;
    for (int v : graph[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        cycleExist |= dfs(v, u);
    }
    return cycleExist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle |= dfs(i);
    }
    if (isCycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "Cycle Not Detected" << endl;
    }

    return 0;
}

/*

5
5
1 2
2 3
3 5
5 4
4 2


8
7
1 2
2 3
3 5
2 4
6 7
6 8
7 8
*/