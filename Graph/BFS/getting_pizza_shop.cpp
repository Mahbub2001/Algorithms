#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
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
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(0);

    int L;
    cin >> L;
    vector<int> vv;
    for(int i = 0;i<=1e5;i++){
        if(level[i] == L){
            if(level[0]) continue;
            vv.push_back(i);
        }
    }
    if (vv.empty())
    {
        cout << -1 << endl;
    }
    else if(level[0] == L){
        cout<<0<<endl;
    }
    else
    {
        for (int val : vv)
        {
            cout << val << " ";
        }
    }

    return 0;
}



// Problem Statement

// Zaman lives in a city of pizzas where every street has several pizza shops and everyone loves pizza there. Suppose there are N pizza shops in Zaman's area. All pizza shops have unique numbers written in the shop, the number of the first pizza shop in his city is from 0 to 10^5. There are E roads between pizza shops, and these pizza shops form a undirected connected graph where you can divide them in levels where the level starts from 0. Zaman lives in level L, now he wants to know which pizza shops are there in his level. Can you help him to get the desired pizza shops?

// Note: If there are no pizza shops at level L, then print -1.

// Input Format

// First line will contain two integers N and E, number of pizza shops and roads repectively.
// The next E lines will contain two integeres A and B, which means there is a road between A and B.
// The last line will contain L, the level where Zaman lives.



// Sample Input 0

// 3 2
// 0 1
// 0 2
// 1
// Sample Output 0

// 1 2 