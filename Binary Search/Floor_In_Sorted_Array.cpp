#include <bits/stdc++.h>
using namespace std;
// largest number in array <=x

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long x;
    cin >> x;
    long long ans = -1, low = 0, high = n - 1;
    while (low <= high)
    {
        long long mid = (high + low) / 2;
        if (v[mid] <= x)
        {
            ans = v[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}

/*
5
20 25 30 35 40
27
ans:
25
*/