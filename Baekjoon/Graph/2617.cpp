#include<bits/stdc++.h>
using namespace std;

int n, m;
int visited[100];

int bfs(vector<vector<int>>& graph ,int start)
{
    fill(visited, visited + 100, 0);
    queue<int> q;
    visited[start] = 1;    
    q.push(start);

    int count = 0;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        // 각 구슬의 인접 구슬 순회
        for (auto item : graph[x])
        {
            if (visited[item] != 0) continue;
            q.push(item);
            visited[item] = 1;
            count++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<int>> graph_h(n + 1);
    vector<vector<int>> graph_l(n + 1);

    for (int i = 0; i < m; i++)
    {
        int heavy, light;
        cin >> heavy >> light;
        graph_h[heavy].push_back(light);
        graph_l[light].push_back(heavy);
    }

    int limit = (n - 1) / 2;
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        int light = bfs(graph_h, i);
        int heavy = bfs(graph_l, i);
        if (heavy > limit || light > limit)
            answer++;
    }

    cout << answer;

    return 0;
}

