#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> graph[1001];

int bfs(int start, int dest)
{
    bool visited[1001] = {0,};    
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start] = true;
    while(q.size())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        // ������ ��ȯ
        if(cur == dest)
        {
            return dist;
        }
        // cur�� ������ ��� ��ȸ
        for(auto [nxt, nxtDist] : graph[cur])
        {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            // 1�� ����� 2, 4 �� dist�� �� ������
            // ���ݱ��� �Ÿ� ŵ
            q.push({nxt, dist + nxtDist});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;
        graph[u].push_back({v,dist});
        graph[v].push_back({u,dist});
    }

    for(int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        // �Ÿ� ���
        int distance = bfs(u,v);
        cout << distance << '\n';
    }
    

    return 0;
}