#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        int total = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            total += A[i];
        }
        if (total % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int l = total / 2;
            vector<vector<bool>> dp(N + 1, vector<bool>(l + 1, false));

            dp[0][0] = true;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j <= l; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= A[i - 1])
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
                    }
                }
            }

            if (dp[N][l])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}


// Problem Statement

// Rahim and Karim are two brothers. They wanted to give a lot of chocolates to their mom. Their mom brought N boxes of chocolates for them. However, in each box, the number of chocolates is not the same, and their mom didn't know it. Now she is very upset because her children want the whole box, and they also want an equal number of chocolates. So she needs your help.

// Can you tell if she could divide those boxes between her children so that both of them get an equal number of chocolates? She can't throw away any boxes, and one box can be taken once.

// Input Format

// First line will contain T, the number of test cases.
// First line of each test case will contain N.
// Second line will contain a list A, the number of chocolates in each box.
// Constraints

// 1 <= T <= 1000
// 1 <= N <= 1000
// 1 <= A[i] <= 1000; 0 <= i < N; Sum of all numbers won't exceed 2000
// Output Format

// Output "YES" if she could divide chocolates into her children, "NO" otherwise.

// Sample Input 0

// 3
// 5
// 1 2 3 4 5
// 4
// 2 3 4 5
// 5
// 1 2 3 8 12
// Sample Output 0

// NO
// YES
// YES