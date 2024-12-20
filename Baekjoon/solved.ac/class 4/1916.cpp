#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
#define BMAX 100001
vector<pair<int, int>> adj[BMAX];
// �ִ� �Ÿ� ���̺�
int dist[MAX];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    // ���, ������
    pq.push({0, start});
    dist[start] = 0;

    while(pq.size())
    {
        auto [cost, cur] = pq.top();
        pq.pop();
        // ��ϵ� ��� < �� ���ñ��� ��� => pass
        if(dist[cur] < cost)
            continue;
        
        // adj�� ������, ��� �����̴�. ���� ȥ�� ���� 
        for(auto [nxt, nxtCost] : adj[cur])
        {
            // ��ϵ� ��뺸�� �۴ٸ� ����
            if(dist[nxt] > nxtCost + cost)
            {
                dist[nxt] = nxtCost + cost;
                pq.push({nxtCost + cost , nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    int start, end; cin >> start >> end;
    
    memset(dist, 98765432, sizeof(dist));
    dijkstra(start);

    cout << dist[end];

    return 0;
}