#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int MAX_N = 1005;
const int MAX_S = 1005;

int dp[MAX_N][MAX_S];

bool subset_sum(vector<int> &a, int n, int s)
{
    if (s == 0)
        return true;
    if (n == 0 || s < 0)
        return false;
    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] <= s)
    {
        return (dp[n][s] = subset_sum(a, n - 1, s - a[n - 1]) || subset_sum(a, n - 1, s));
    }
    else
    {
        return (dp[n][s] = subset_sum(a, n - 1, s));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, u;
        cin >> n >> u;
        int s = 1000 - u;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        memset(dp, -1, sizeof(dp));
        if (subset_sum(a, n, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}


// Problem Statement

// Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, but he can choose each mark only once.

// Can you tell if he can select marks from this list in such a way that his total marks add up to 1000?

// Input Format

// First line will contain T, the number of test cases.
// First line of each test case will contain N and M.
// Second line of each test case will contain a list A of N marks.
// Constraints

// 1 <= T <= 1000
// 1 <= N, M <= 1000
// 1 <= A[i] <= 100; 0 <= i < N
// Output Format

// Output "YES" if he can obtain perfect score of 1000, "NO" otherwise.

// Sample Input 0

// 3
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 6 900
// 10 20 30 40 50 60
// Sample Output 0

// YES
// NO
// YES