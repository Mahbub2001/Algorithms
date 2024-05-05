#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n; i > 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i - 1] == s[j - 1])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void LCS(string str1, string str2)
// {
//     int n = str1.size();
//     int m = str2.size();
//     int dp[n + 1][m + 1];

//     for (int i = 0; i < n + 1; i++)
//     {
//         for (int j = 0; j < m + 1; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 0;
//         }
//     }

//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < m + 1; j++)
//         {
//             if (str1[i - 1] == str2[j - 1])
//             {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     int i = n, j = m;
//     string ans = "";
//     while (i > 0 && j > 0)
//     {
//         if (str1[i - 1] == str2[j - 1])
//         {
//             ans.push_back(str1[i - 1]);
//             i--;
//             j--;
//         }
//         else
//         {
//             if (dp[i][j - 1] > dp[i - 1][j])
//             {
//                 j--;
//             }
//             else
//             {
//                 i--;
//             }
//         }
//     }
//     cout << dp[n][m] << endl;
//     cout << ans << endl;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     string t(s.rbegin(), s.rend());
//     LCS(s, t);

//     return 0;
// }
