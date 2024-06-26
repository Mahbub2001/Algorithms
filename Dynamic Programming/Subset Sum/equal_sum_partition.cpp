#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int s = 0;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 2 == 0)
    {
        int sum = s / 2;
        int dp[n + 1][sum + 1];
        dp[0][0] = true;
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][sum])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

/*
4
1 4 9 4

*/

// bottom up approach

// #include <bits/stdc++.h>
// using namespace std;

// int dp[1005][1005];

// bool solve(int n, int s, int a[])
// {
//     if(n == 0 || s == 0)
//     {
//         if(s == 0) return true;
//         return false;
//     }

//     if(dp[n][s] != -1) return dp[n][s];

//     if(a[n - 1] <= s)
//     {
//         int op1 = solve(n - 1, s - a[n - 1], a);
//         int op2 = solve(n - 1, s, a);

//         return dp[n][s] = op1 || op2;
//     }

//     return dp[n][s] = solve(n - 1, s, a);
// }

// int main()
// {
//     int n, s= 0;
//     cin >> n;

//     int a[n];

//     for(int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         s += a[i];
//     }

//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <= s; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }

//     if(s % 2 == 0)
//     {
//         bool ans = solve(n, s / 2, a);

//         if(ans) cout << "YES";
//         else cout << "NO";
//     }
//     else
//     {
//         cout << "NO";
//     }
// }