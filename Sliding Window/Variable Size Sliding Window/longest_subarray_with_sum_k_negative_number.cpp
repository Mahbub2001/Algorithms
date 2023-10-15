//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        unordered_map<int, int> mp;

        int sum = 0, mx = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum == K)
            {
                mx = max(mx, i + 1);
            }
            if (mp.find(sum - K) != mp.end())
            {
                mx = max(mx, i - mp[sum - K]);
            }
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return mx;
    }
};


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
