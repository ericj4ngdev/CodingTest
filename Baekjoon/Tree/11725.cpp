#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int SIZE = 100'004;
vector<int> adj[SIZE];
int p[SIZE];

void bfs(int root)
{
    // 노드담는 큐
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        // 시작이 root노드라 rootnode -> 자식순으로 순회        
        // cur에 인접한 노드 순회
        for (int nx : adj[cur])
        {
            // cur의 부모이면 pass
            if (p[cur] == nx) continue;
            // 큐에 nx넣기
            q.push(nx);
            // nx의 부모를 cur로 지정
            p[nx] = cur;
        }
    }
}

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n - 1 ; i++)
    {
        int lc, rc;
        cin >> lc >> rc;
        adj[lc].push_back(rc);
        adj[rc].push_back(lc);
    }

    bfs(1);

    for (int i = 2; i <= n; i++)
    {
        cout << p[i] << '\n';
    }


    return 0;
}