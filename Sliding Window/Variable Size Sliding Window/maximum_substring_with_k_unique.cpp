#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    int i = 0, j = 0;
    int freq[26] = {0};
    int unique = 0;
    while (j < n)
    {
        freq[s[j] - 'a']++;
        if (freq[s[j] - 'a'] == 1)
        {
            unique++;
        }
        while (unique > k)
        {
            freq[s[i] - 'a']--;

            if (freq[s[i] - 'a'] == 0)
            {
                unique--;
            }
            i++;
        }
        if (unique == k)
        {
            cout << j - i + 1 << endl;
        }
        j++;
    }
    return 0;
}

// ababadzzcabkc
// 3