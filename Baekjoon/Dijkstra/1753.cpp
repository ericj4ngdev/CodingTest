#include<bits/stdc++.h>
using namespace std;

int vertics, edges, start;
vector<pair<int,int>> adj[20005];
const int INF = 1e9+10;
int d[20005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> vertics >> edges >> start;
    fill(d, d + vertics + 1, INF);
    while(edges--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>,
     greater<pair<int,int>>> pq;
    d[start] = 0;

    // 처음 출발지점 (0,1) 넣고 시작
    pq.push({d[start], start});
    while(!pq.empty())
    {
        // first = 거리
        // second = 노드        
        // 매번 가장 가까운 노드를 뽑는다. 
        auto cur = pq.top();
        pq.pop();
        // 테이블 검사
        if(d[cur.second] != cur.first) continue;
        // 인접한 노드 순회 = nxt
        for (pair<int,int> nxt : adj[cur.second])
        {
            // 테이블에 있는 최소 거리 <= 지금까지 거리 + 인접 노드 거리
                // => 무시
            if(d[nxt.second] <= d[cur.second] + nxt.first)
                continue;
            // 그렇지 않으면 갱신
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    for(int i = 1; i <= vertics; ++i)
    {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }

    return 0;
}

