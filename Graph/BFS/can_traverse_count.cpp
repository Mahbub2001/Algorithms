#include <bits/stdc++.h>
using namespace std;

void bfs(int K, int N, vector<int> graph[])
{
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(K);
    visited[K] = true;
    int count = -1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        count++;

        for (int v : graph[x])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << count << endl;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<int> graph[N];
    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
    int K;
    cin >> K;
    bfs(K, N, graph);

    return 0;
}


// Problem Statement

// Kamal lives in mazenda city. In his neighbourhood there are several houses too. Some of them are directly connected to Kamal's house, and some of them are indirectly connected. This time the roads are only one-way. If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1. Can you tell how many houses Kamal can go directly or indirectly if Kamal's house if his house number is K?

// Note: You can go in the road only in one direction.

// Input Format

// First line will contain N and E, the number of houses and roads respectively.
// Next E lines will contain A and B, means there is a road between A house and B house. You can go only from A to B.
// Next line will contain K, the number of Kamal's house

// Sample Input 1

// 6 5
// 0 1
// 0 2
// 2 3
// 3 0
// 4 5
// 2
// Sample Output 1

// 3