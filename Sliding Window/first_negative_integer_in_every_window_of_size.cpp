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
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    long long i = 0, j = 0;
    queue<long long> q;
    while (j < N)
    {
        if (A[j] < 0)
            q.push(A[j]);
        if (j >= K - 1)
        {
            if (q.size())
                cout << q.front() << " ";
            else
                cout << 0 << " ";
            if (A[i] < 0)
                q.pop();
            i++;
        }
        j++;
    }

    return 0;
}


/*
8
2 -3 -1 5 -2 2 1 5
4
*/