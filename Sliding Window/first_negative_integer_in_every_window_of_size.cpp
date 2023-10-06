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
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
/* implementing a sliding window technique to find the first negative integer in each
window of size K in an array A. */
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