#include<bits/stdc++.h>
using namespace std;

const int CITIES = 101;
vector<pair<int,int>> adj[CITIES];

// graph[i][j] = i -> j 로 가는데 드는 비용

void bfs(int start, vector<vector<int>>& graph)
{
    bool visited[CITIES];
    // cost, end
    queue<pair<int,int>> q;
    q.push({0, start});
    visited[start] = true;
    
    while(q.size())
    {
        int curCost = q.front().first;
        int cur = q.front().second;
        q.pop();
        // 인접 도시 순회
        // for(int i = 0; i < adj; ++i)
        for(auto [nxt, nxtCost] : adj[cur])
        {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            if(graph[start][nxt] != 0)
            {
                graph[start][nxt] = min(graph[start][nxt], nxtCost + curCost);
            }
            else
            {
                graph[start][nxt] = nxtCost + curCost;
            }
            
            // 최소인가?
            q.push({nxtCost + curCost, nxt});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;   cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    vector<vector<int>> graph(n);
    // 도시-도시별 비용 
    for(int i = 1; i <= m; ++i)
    {
        bfs(i, graph);
    }

    for(const vector<int>& city : graph)
    {
        for(int cost : city)
        {
            cout << cost << " ";
        }
        cout << '\n';
    }

    return 0;
}