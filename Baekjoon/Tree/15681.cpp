#include<bits/stdc++.h>
using namespace std;

const int MXN = 10e5 + 10;
vector<int> adj[MXN];
int parent[MXN];
int subtreeSize[MXN]; // 서브트리 크기를 저장하는 배열

// 서브트리 크기를 계산하는 dfs 함수
int dfs(int cur) {
    subtreeSize[cur] = 1; // 현재 노드 포함
    for (int nxt : adj[cur]) {
        if (parent[cur] == nxt) continue; // 부모 노드는 다시 방문하지 않음
        // 부모 설정
        parent[nxt] = cur;
        // 자식 노드의 서브트리 크기 합산
        subtreeSize[cur] += dfs(nxt); 
    }
    return subtreeSize[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;


    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 부모 배열 설정 및 서브트리 크기 계산
    parent[r] = -1; // 루트 노드의 부모는 없으므로 -1로 설정
    dfs(r);

    // 쿼리 처리
    for (int i = 0; i < q; ++i) {
        int u;
        cin >> u;
        cout << subtreeSize[u] << '\n';
    }

    return 0;
}
