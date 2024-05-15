#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}

// top down approach

// #include <bits/stdc++.h>
// using namespace std;

// int dp[1005][1005] = {-1};

// int lcs(string a, int n, string b, int m)
// {
//     if(n == 0 || m == 0) return 0;

//     if(dp[n][m] != -1) return dp[n][m];

//     if(a[n - 1] == b[m - 1])
//     {
//         return dp[n][m] = 1 + lcs(a, n - 1, b, m - 1);
//     }
//     else
//     {
//         int op1 = lcs(a, n - 1, b, m);
//         int op2 = lcs(a, n, b, m - 1);

//         return dp[n][m] = max(op1, op2);
//     }
// }

// int main()
// {
//     string a, b;
//     cin >> a >> b;

//     memset(dp, -1, sizeof(dp));

//     cout << lcs(a, a.size(), b, b.size());
// }