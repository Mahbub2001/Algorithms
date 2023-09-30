#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define pi pair<int, int>

const int N = 1005;
int dis[N][N];
bool vis[N][N];
int n, m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && !vis[cI][cJ])
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ))
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    char a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '-')
            {
                vis[i][j] = true;
            }
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs(si, sj);

    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}


// Problem Statement

// You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// You will be given the indexes of to cells - S(si,sj) and D(di,dj). You need to tell if these cells are in the same component or not where you can go from S to D.

// Input Format

// First line will contain N and M.
// Next you will be given the 2D matrix.
// Next line will contain si and sj.
// Last line will contain di and dj.


// Sample Input 0

// 5 4
// ..-.
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2
// Sample Output 0

// NO
// Sample Input 1

// 5 4
// ....
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2
// Sample Output 1

// YES