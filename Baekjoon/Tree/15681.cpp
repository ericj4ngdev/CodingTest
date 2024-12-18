#include<bits/stdc++.h>
using namespace std;

const int MXN = 10e5 + 10;
vector<int> adj[MXN];
int parent[MXN];
int subtreeSize[MXN]; // ����Ʈ�� ũ�⸦ �����ϴ� �迭

// ����Ʈ�� ũ�⸦ ����ϴ� dfs �Լ�
int dfs(int cur) {
    subtreeSize[cur] = 1; // ���� ��� ����
    for (int nxt : adj[cur]) {
        if (parent[cur] == nxt) continue; // �θ� ���� �ٽ� �湮���� ����
        // �θ� ����
        parent[nxt] = cur;
        // �ڽ� ����� ����Ʈ�� ũ�� �ջ�
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

    // �θ� �迭 ���� �� ����Ʈ�� ũ�� ���
    parent[r] = -1; // ��Ʈ ����� �θ�� �����Ƿ� -1�� ����
    dfs(r);

    // ���� ó��
    for (int i = 0; i < q; ++i) {
        int u;
        cin >> u;
        cout << subtreeSize[u] << '\n';
    }

    return 0;
}
