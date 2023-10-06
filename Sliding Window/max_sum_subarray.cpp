#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    /* finding the maximum sum of a subarray of length K in an array. */
    long long i = 0, j = 0, s = 0;
    long long mx = LLONG_MIN;
    while (j < N)
    {
        s += Arr[j];
        if (j >= K - 1)
        {
            mx = max(mx, s);
            s -= Arr[i];
            i++;
        }
        cout << s << endl;
        j++;
    }
    cout << mx << endl;

    return 0;
}

/*
6
5 2 6 1 3 4
3

*/