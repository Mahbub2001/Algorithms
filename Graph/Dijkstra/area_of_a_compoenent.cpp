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

int bfs(int si, int sj)
{
    int area = 0;
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        area++; 

        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ))
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
            }
        }
    }

    return area;
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

    vector<int> arears;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                int area = bfs(i, j);
                arears.push_back(area);
            }
        }
    }

    if (arears.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        int min_area = *min_element(arears.begin(), arears.end());
        cout << min_area << endl;
    }

    return 0;
}














// Problem Statement

// You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

// Note: If there are no components, print -1.

// Input Format

// First line will contain N and M.
// Next you will be given the 2D matrix.

// Sample Input 0

// 6 5
// ..-..
// ..-..
// -----
// .-...
// .----
// .....
// Sample Output 0

// 3
// Sample Input 1

// 3 3
// ---
// ---
// ---
// Sample Output 1

// -1