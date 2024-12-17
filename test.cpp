#include<bits/stdc++.h>
using namespace std;

int visited[100];

int bfs(vector<vector<int>>& graph, int start)
{
    memset(visited, 0, sizeof(visited));
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph[cur].size(); i++)
        {
            if(visited[graph[cur][i]] == 1)
                continue;
            visited[graph[cur][i]] = 1;
            count++;
            // 가벼운 거 체크
            q.push(graph[cur][i]);
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph_heavy(n+1);
    vector<vector<int>> graph_light(n+1);

    for(int i = 0; i < m; i++)
    {
        int heavy, light;
        cin >> heavy >> light;
        graph_heavy[heavy].push_back(light);
        graph_light[light].push_back(heavy);
    }

    // 중간이 될 수 없다. = light, heavy 개수 둘 중 하나가 (n-1)/2보다 크다
    // light, heavy 개수는 어떻게 체크?
    // bfs
    int limit = (n-1)/2;
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = bfs(graph_heavy, i);
        int h = bfs(graph_light, i);
        if(l > limit || h > limit) answer++;        
    }

    cout << answer;

    return 0;
}