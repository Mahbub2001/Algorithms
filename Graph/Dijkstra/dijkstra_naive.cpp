#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

const int N = 1e5 + 5;
int dis[N];
vector<pair<int, int>> v[N];

void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            pair<int, int> child = v[parent][i];
            int childNOde = child.first;
            int child_cost = child.second;

            if (dis[parent] + child_cost < dis[childNOde])
            {
                dis[childNOde] = dis[parent] + child_cost;
                q.push(childNOde);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"Node "<<i << " Distance : "<<dis[i]<<endl;
    }
    

    return 0;
}

/*
5 7
1 3 2
1 2 10
2 3 1
3 4 2
4 5 7
2 4 3
2 5 2

*/