#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;

    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == s)
        {
            cout << i + 1 << endl;
        }
        if (sum > s)
        {
            /* This code snippet is checking if the current sum minus the target sum `s` exists in the
            `mp` map. If it does, it means that there is a subarray with a sum equal to `s`. */
            if (mp.find(sum - s) != mp.end())
            {
                cout << i - mp[sum - s] << endl;
            }
            /* This code snippet is checking if the current sum `sum` exists in the `mp` map. If it does not exist,
            it means that the current sum has not been encountered before. In that case, it adds the current sum
            `sum` as a key in the map and assigns its value as the current index `i`. This is done to keep track
            of the first occurrence of each sum encountered during the iteration. */
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
    }

    return 0;
}

// 9
// 10 2 3 95 5 -99 -1 10
// 6

// longest subarray