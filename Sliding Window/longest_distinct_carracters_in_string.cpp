//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

int longestSubstrDistinctChars(string S)
{
    int i = 0, j = 0, mx = 0;
    map<char, int> mp;
    for (int j = 0; j < S.size(); j++)
    {
        mp[S[j]]++;
        while (mp[S[j]] > 1)
        {
            mp[S[i]]--;
            i++;
        }
        mx = max(mx, j - i + 1);
    }
    return mx;
}