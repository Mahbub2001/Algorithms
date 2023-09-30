#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define pi pair<int, int>

const int N = 105;
int dist[N][N];
bool vis[N][N];
int n, m;
vector<pi> path = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isValid(int cI, int cJ)
{
    return cI >= 0 && cI < n && cJ >= 0 && cJ < m;
}

int bfs(int si, int sj, int ai, int aj)
{
    queue<pi> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    vis[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();

        if (pI == ai && pJ == aj)
            return dist[ai][aj];

        for (int i = 0; i < 8; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;

            if (isValid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dist[cI][cJ] = dist[pI][pJ] + 1;
            }
        }
    }

    return -1; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m;
        memset(dist, -1, sizeof(dist));
        memset(vis, false, sizeof(vis));

        int si, sj, ai, aj;
        cin >> si >> sj >> ai >> aj;

        int result = bfs(si, sj, ai, aj);

        cout << result << endl;
    }

    return 0;
}


// Problem Statement

// You will be given an undirected graph where there will be N nodes and E edges. You need to tell the number of edges that can create a cycle in the graph.

// Note: Duplicate edges as input can not be possible. The value of nodes are from 1 to N.

// Input Format

// First line will contain N and E.
// Next E lines will contain A and B which means there is a edge between A and B.
// Constraints

// 1 <= N <= 10^5
// 1 <= E <= (N*(N-1))/2
// 1 <= A, B <= N
// Output Format

// Output the number of edges that can create a cycle.

// Sample Input 0

// 5 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3
// Sample Output 0

// 3
// Sample Input 1

// 3 3
// 1 2
// 2 3
// 1 3
// Sample Output 1

// 1