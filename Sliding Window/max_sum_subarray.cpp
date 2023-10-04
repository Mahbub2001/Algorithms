#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define fill_number(x, n) setfill('0') << setw(n) << (x)
#define precision_number(x, n) fixed << setprecision(n) << (x)
template <typename T>
T lcm(T a, T b)
{
    return (a * (b / __gcd(a, b)));
}

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