#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,Q;
    cin >> n >>Q;
    long long int arr[n];
    long long int pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = arr[i] + pre[i - 1];
    }
    int L, R;
    while (Q--)
    {
        cin >> L >> R;
        L--;
        R--;
        if (L == 0){
            cout<< pre[R]<<" "<<endl;
        }
        else{
            cout<<pre[R]-pre[L-1]<<" "<<endl;
        }
    }

    return 0;
}