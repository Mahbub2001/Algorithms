#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int dp[1005][1005];

int subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
    {
        int opt1 = subset_sum(n - 1, a, s - a[n - 1]);
        int opt2 = subset_sum(n - 1, a, s);
        return dp[n][s] = opt1 + opt2;
    }
    else
    {
        return dp[n][s] = subset_sum(n - 1, a, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    // cout << subset_sum(n, a, s) << endl

    // bottom up
    int dp1[n + 1][s + 1];
    dp1[0][0] = 1;
    for (int i = 1; i <= s; i++)
    {
        dp1[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                // bool op1 = dp1[i - 1][j - a[i - 1]];
                // bool op2 = dp1[i - 1][j];
                // dp1[i][j] = op1 || op2;
                dp1[i][j] = dp1[i - 1][j - a[i - 1]] + dp1[i - 1][j];
            }
            else
            {
                dp1[i][j] = dp1[i - 1][j];
            }
        }
    }
    cout<<dp1[n][s]<<endl;

    return 0;
}
// 2 vabe kora jabe

/*
6
1 2 3 4 5 6
7
*/