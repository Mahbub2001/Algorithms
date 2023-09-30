#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int dp[1005][1005];

int unbounded_knapsack(int n, int s, int val[], int w[])
{
    if (s == 0 || n == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        int choice1 = val[n - 1] + unbounded_knapsack(n, s - w[n - 1], val, w);
        int choice2 = unbounded_knapsack(n - 1, s, val, w);
        return dp[n][s] = max(choice1, choice2);
    }
    else
    {
        return dp[n][s] = unbounded_knapsack(n - 1, s, val, w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int val[n], w[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        w[i] = i + 1;
    }
    cout << unbounded_knapsack(n, n, val, w) << endl;

    return 0;
}

/*
8
2 4 4 5 8 10 12 9

8 is also capacity;

*/