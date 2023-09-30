#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<"Index "<<i<<": ";
        for (int j = 0; j <adj[i].size(); j++)
        {
           cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;
}

/*
4 4
1 2
4 1
1 3
3 4
 
*/









/*

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> graph[200];
    vector<pair<int, int>> graph[200]; // for weighted

    int n, m;
    cin >> n >> m;

    // weighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // for undirected
    }
    // // unweighted graph
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);//for undirected
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (auto j : graph[i])
        {
            cout << "( "<< j.first <<" "<<j.second <<" )"<< " ";
        }
        cout << endl;
    }

    return 0;
}

/*
4
5
1 2
1 3
2 4
4 3
3 2

*/
/*
4
5
1 2 8
1 3 9
2 4 11
4 3 17
3 2 15

*/
