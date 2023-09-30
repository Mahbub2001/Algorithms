#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int dp[1005][1005];

int Knapsack(int n, int s, int v[], int w[])
{

    if (n == 0 || s == 0)
    {
        return 0;
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (w[n - 1] <= s)
    {
        int op1 = Knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = Knapsack(n - 1, s, v, w);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = Knapsack(n - 1, s, v, w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << Knapsack(n, s, v, w);

    return 0;
}

/*
4
1 5 3 2
5 2 4 3
7
*/