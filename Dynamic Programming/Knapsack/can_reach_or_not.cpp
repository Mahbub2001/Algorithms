#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

const int MAX_N = 100005; 
bool dp[MAX_N];

bool can_reach(int n)
{
    dp[1] = true; 
    for (int i = 2; i <= n; i++)
    {
        dp[i] = false; 
        if (i >= 3 && dp[i - 3])
        {
            dp[i] = true; 
        }
        if (i % 2 == 0 && dp[i / 2])
        {
            dp[i] = true;
        }
    }
    return dp[n];
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
        int n;
        cin >> n;

        if (can_reach(n))
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

// You will be given a positive integer N. You will start from 1 and do some steps (possibly zero).

// In each step you can choose one of the following:

// Add 3 with the current value
// Multiply by 2 with the current value
// Can you tell if you can reach N by using any number of steps you want.

// Input Format

// First line will contain T, the number of test cases.
// In each test case you will be given N.


// Sample Input 0

// 5
// 1
// 3
// 5
// 15
// 16
// Sample Output 0

// YES
// NO
// YES
// NO
// YES