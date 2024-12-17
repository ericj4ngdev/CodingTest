#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    // 거리를 pair 로 저장한다. 
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < n - 1; ++i)
    {
        int l, r, d;
        cin >> l >> r >> d;
        graph[l].push_back({r,d});
        graph[r].push_back({l,d});
    }

    // 그래프 bfs해서 도착지점까지 거리
    // 1 2 입력
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        queue<pair<int,int>> q;
        vector<bool> visited(n+1);
        q.push({u,0});              // 시작점, 거리 입력
        visited[u] = true;

        while(q.size())
        {
            auto [cur, distance] = q.front();
            q.pop();
            // 도착지점이면 거리 반환, 끝!
            if(cur == v)
            {
                cout << distance << '\n';
                break;
            }
            // 그래프 순회돌면서 인접 노드 큐에 넣기
            for(auto[nxt, nextDist] : graph[cur])
            {
                if(visited[nxt]) continue;
                visited[nxt] = true;
                // 순회돌면서 to까지 가는데 거리 합
                q.push({nxt, distance + nextDist});
            }
        }
    }
    
    return 0;
}