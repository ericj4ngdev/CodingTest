#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10'001;
vector<pair<int, int>> tree[SIZE];
bool visited[SIZE];

pair<int, int> dfs(int node, int dist) {
    visited[node] = true;
    pair<int, int> farthest = {dist, node}; // {거리, 노드}

    for (auto [next, cost] : tree[node]) {
        if (!visited[next]) {
            pair<int, int> result = dfs(next, dist + cost);
            if (result.first > farthest.first) {
                farthest = result; // 가장 먼 거리 갱신
            }
        }
    }

    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        tree[u].push_back({v, cost});
        tree[v].push_back({u, cost});
    }

    // 첫 번째 DFS: 임의의 노드(1번)에서 가장 먼 노드 찾기
    memset(visited, false, sizeof(visited));
    pair<int, int> first = dfs(1, 0);

    // 두 번째 DFS: 가장 먼 노드에서 다시 DFS 수행하여 트리의 지름 계산
    memset(visited, false, sizeof(visited));
    pair<int, int> second = dfs(first.second, 0);

    cout << second.first << '\n';
    return 0;
}
