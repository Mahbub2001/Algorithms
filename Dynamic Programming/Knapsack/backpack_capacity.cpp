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

    int T;
    cin >> T;
    while (T--)
    {
        int n, s;
        cin >> n >> s;
        int v[n], w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << Knapsack(n, s, v, w) << endl;
    }
    return 0;
}



// Problem Statement

// Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to carry all of his equipment with him.

// The treasure hunter had a backpack with a limited weight capacity, and he could only carry a certain amount of equipment with him. Each piece of equipment had its own weight and value, and the treasure hunter needed to choose which items to bring to maximize the total value while keeping the total weight under the limit.

// Help the treasure hunter to choose which items to bring in his backpack to maximize their total value while keeping the total weight of his backpack under a certain limit. Each item can only be included once.

// Input Format

// First line will contain T, the number of test cases.
// The first line of each test case will contain N(Number of items) and W(Total weight of backpack).
// Second line of each test case will contain an array w containing the weights of all items.
// Third line of each test case will contain an array v containting the values of all items.
// Constraints

// 1 <= T <= 1000
// 1 <= N <= 1000
// 0 <= W <= 1000
// 0 <= w[i] <= 1000; Here 0 <= i < N
// 0 <= v[i] <= 1000; Here 0 <= i < N


// Sample Input 0

// 2
// 4 7
// 2 3 4 5
// 4 7 6 5
// 4 17
// 10 1 6 9
// 6 10 10 8
// Sample Output 0

// 13
// 28
// Explanation 0

// In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total value is 7+6=13 and its the maximum value possible.