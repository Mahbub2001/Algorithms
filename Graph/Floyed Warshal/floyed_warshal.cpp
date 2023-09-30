#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int INF = 1e7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (dis[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    cout << "Updated: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (dis[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
4 6
1 2 3
2 1 2
1 4 5
4 3 2
3 2 1
2 4 4

*/

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n";

// const int N = 1e3 + 7;
// const int INF = 1e9 + 7;
// int d[N][N];
// int n, m;

// void print_matrix()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << d[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void dist_initialize()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i != j)
//             {
//                 d[i][j] = INF;
//             }
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;

//     dist_initialize();

//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         d[u][v] = w;
//         d[v][u] = w;
//     }

//     for (int k = 1; k <= n; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 0; j <= n; j++)
//             {
//                 d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//             }
//         }
//     }

//     cout << "After floyd Warshaall: " << endl;

//     print_matrix();

//     return 0;
// }

// /*

// 5
// 7
// 1 2 2
// 1 3 6
// 2 3 1
// 3 4 4
// 4 2 6
// 2 5 3
// 5 4 9

// */