#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string p, int m, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     cout << lps[i] << " ";
    // }
}

int main()
{
    string s = "ababcababcabcabc";
    string p = "ababcabc";
    int m = p.size();
    vector<int> lps(m, 0);
    computeLPSArray(p, m, lps);

    int n = s.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && s[i] != p[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return 0;
}
