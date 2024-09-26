#include<bits/stdc++.h>
using namespace std;

int node, edge, start;
vector<pair<int, int>> graph;
map<int, vector<int>> nodes;
bool visited[1001];

void dfs(int curnode)
{
    visited[curnode] = true;
    cout << curnode << " ";
    
    // 인접한 노드 순회
    for(int it : nodes[curnode])
    {
        if(visited[it]) continue;
        // 방문 시 재귀        
        dfs(it);
    }
}

void bfs(int curnode)
{
    visited[curnode] = true;
    queue<int> q;
    q.push(curnode);

    while(q.size())
    {
        int nx = q.front();
        cout << nx << " ";
        q.pop();

        // 인접한 노드 순회
        for(int it : nodes[nx])
        {
            if(visited[it]) continue;
            visited[it] = true;
            q.push(it);
        }        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> node >> edge >> start;

    for(int i = 0; i < edge; i++)
    {
        int lnode, rnode;
        cin >> lnode >> rnode;
        nodes[lnode].push_back(rnode);
        nodes[rnode].push_back(lnode);
    }
    
    // 정렬
    // i는 0부터가 아니라 1부터..
    // 노드 0은 없다. 
    for(int i = 1; i <= node; i++)
    {
        // 오름차순 정렬 
        sort(nodes[i].begin(), nodes[i].end());
    }

    // 노드 순회 
    dfs(start);
    memset(visited, 0, sizeof(visited));
    cout << '\n';
    bfs(start);

    return 0;
}