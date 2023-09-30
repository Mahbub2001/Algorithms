#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define lcm(a, b) ((a / GCD(a, b)) * b)

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

    int n, s;
    cin >> n >> s;
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
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << unbounded_knapsack(n, s, val, w) << endl;

    return 0;
}

/*

4 6
5 3 2 4
4 1 3 2

*/