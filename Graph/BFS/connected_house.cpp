
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;

    vector<int> graph[N];
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    int K;
    cin >> K;
    int count = graph[K].size();
    cout << count << endl;

    return 0;
}



// Problem Statement

// Kamal lives in mazenda city. In his neighbourhood there are several houses too. Some of them are directly connected to Kamal's house, and some of them are indirectly connected. But the roads are two-way as usual. If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1. Can you tell how many houses are directly connected to Kamal's house if his house number is K?

// Input Format

// First line will contain N and E, the number of houses and roads respectively.
// Next E lines will contain A and B, means there is a road between A house and B house. You can go from A to B and also B to A.
// Next line will contain K, the number of Kamal's house


// Sample Input 0

// 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2
// Sample Output 0

// 2