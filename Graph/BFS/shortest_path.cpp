#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int n = 1e5 + 5;
vector<int> v[n];
bool vis[n];
int dis[n];
int par[n];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    par[s] = -1;
    vis[s] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (!vis[child])
            {
                q.push(child);
                par[child] = parent;
                dis[child] = dis[parent]+1;
                vis[child] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);
    for (int i = 1; i <=n; i++)
    {
       cout<<"Node "<<i<<": "<<par[i]<<endl;
    }

    int d;
    cin>>d;
    if(vis[d]){
        int x=d;
        vector<int>a;
        while(x!= -1){
            a.push_back(x);
            x = x[par];
        }
        reverse(a.begin(), a.end());
        for(int val:a){
            cout<<val<<" ";
        }
    }
    else{
        cout<<"NO PATH"<<endl;
    }
    

    return 0;
}

/*

5 7
1 3 
1 2 
2 3 
3 4 
4 5 
2 4 
2 5 

*/