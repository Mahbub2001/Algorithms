#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};
int find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout<<find(4)<<endl;

    return 0;
}

/*
8



*/