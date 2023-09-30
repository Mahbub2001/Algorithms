#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
bool visited[N];

void dfs(int u)
{
    // section 1 : actions just after entering the node u
    visited[u] = true;
    cout<<"Visiting node : "<<u <<endl; 

    for (int v : graph[u])
    {
        // section 2: actions before entering a new neighbour/child
        if (visited[v] == true)
            continue;
        dfs(v);
        // section 3: actions after existing a neighbour
    }
    // section 4: actions before exiting a node u
}

int main()
{

    int n, m;
    cin >> n >> m;

    // unweighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // for undirected
    }

    dfs(1);

    return 0;
}

/*
10
9
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9
////////
9
10
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9

*/