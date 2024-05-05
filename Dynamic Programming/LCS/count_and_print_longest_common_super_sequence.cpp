#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << m + n - dp[n][m] << endl;

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                ans.push_back(s2[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(s1[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
