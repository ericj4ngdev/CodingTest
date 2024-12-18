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
        // 도착시 반환
        if(cur == dest)
        {
            return dist;
        }
        // cur와 인접한 노드 순회
        for(auto [nxt, nxtDist] : graph[cur])
        {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            // 1과 연결된 2, 4 에 dist가 다 더해짐
            // 지금까지 거리 킵
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
        // 거리 출력
        int distance = bfs(u,v);
        cout << distance << '\n';
    }
    

    return 0;
}