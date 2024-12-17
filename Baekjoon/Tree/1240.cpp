#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    // �Ÿ��� pair �� �����Ѵ�. 
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < n - 1; ++i)
    {
        int l, r, d;
        cin >> l >> r >> d;
        graph[l].push_back({r,d});
        graph[r].push_back({l,d});
    }

    // �׷��� bfs�ؼ� ������������ �Ÿ�
    // 1 2 �Է�
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        queue<pair<int,int>> q;
        vector<bool> visited(n+1);
        q.push({u,0});              // ������, �Ÿ� �Է�
        visited[u] = true;

        while(q.size())
        {
            auto [cur, distance] = q.front();
            q.pop();
            // ���������̸� �Ÿ� ��ȯ, ��!
            if(cur == v)
            {
                cout << distance << '\n';
                break;
            }
            // �׷��� ��ȸ���鼭 ���� ��� ť�� �ֱ�
            for(auto[nxt, nextDist] : graph[cur])
            {
                if(visited[nxt]) continue;
                visited[nxt] = true;
                // ��ȸ���鼭 to���� ���µ� �Ÿ� ��
                q.push({nxt, distance + nextDist});
            }
        }
    }
    
    return 0;
}