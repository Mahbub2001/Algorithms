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

// You will be given a chessboard of NxM size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K(Ki and Kj), and the queen's cell Q(Qi and Qj). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

// A knight move in 8 directions. The directions are given below:image

// Input Format

// First line will contain T, the number of test cases.
// First line of each test case will contain N and M.
// Second line of each test case will contain Ki and Kj.
// Third line of each test case will contain Qi and Qj.

// Sample Input 0

// 4
// 8 8
// 0 0
// 7 7
// 5 6
// 0 1
// 0 1
// 4 4
// 0 0
// 0 1
// 2 2
// 0 0
// 0 1
// Sample Output 0

// 6
// 0
// 3
// -1