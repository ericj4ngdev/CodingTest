#include<bits/stdc++.h>
using namespace std;

int n, m;
int to, from;
int dp[10001], mx, visited[10001];
vector<int> v[10001];

int dfs(int here)
{
    visited[here] = 1;
    int ret = 1;
    for(int there : v[here])
    {
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    while(m--)
    {
        cin >> to >> from;
        // 연결된 노드 번호
        v[from].push_back(to);
    }
    
    for(int i = 1; i <= n; i++)
    {
        memset(visited, 0 , sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(mx == dp[i])
        {
            cout << i << " ";
        }
    }
    
    return 0;
}