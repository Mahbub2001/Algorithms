#include <bits/stdc++.h>
using namespace std;
int flag[1005];
const int N = 1e5 + 5;
vector<int> graph[N];
vector<int>c;
bool visited[N];

void bfs(int s)
{
    queue<int> q;
    int count =0;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;
        for (int v : graph[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
        }
    }
    c.push_back(count);
}


int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    int m = 1000;
    for(int i =0; i<= m; i++){
        if(visited[i] == true) continue;
        bfs(i);
    }

    sort(c.begin(), c.end());
    for(int val:c){
        if(val == 1) continue;
        cout<<val<<" ";
    }


    return 0;
}


// Problem Statement

// You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

// Note: There will be no component with single node.

// Input Format

// First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
// Next E lines will contain A, B which means there is a edge between node A and B.

// Sample Input 0

// 9 7
// 0 1
// 1 2
// 0 2
// 2 3
// 4 5
// 5 7
// 8 9
// Sample Output 0

// 2 3 4 


// Sample Input 1

// 5 3
// 999 1000
// 100 500
// 500 600
// Sample Output 1

// 2 3