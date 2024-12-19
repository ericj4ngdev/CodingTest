#include <bits/stdc++.h>
using namespace std;

int bfs(long a, long b) 
{
    queue<pair<long, int>> q; // {���� ��, ���� Ƚ��}
    q.push({a, 1}); // ���� ���� �ʱ� ���� Ƚ��
    
    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        // ��ǥ���� ������ ���
        if (cur == b) {
            return cnt;
        }

        // ������ ���� ���� Ž��
        for (long nxt : {cur * 2, cur * 10 + 1}) 
        {
            // b�� �ʰ��ϸ� Ž�� �ߴ�
            // ���� ���⶧���� q.size()�� 0�� �ȴ�. 
            if (nxt > b) continue; 
            q.push({nxt, cnt + 1}); // ť�� ���ο� ���� �߰�
        }
    }

    return -1; // ��ǥ���� �������� ���� ���
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long a, b;
    cin >> a >> b;

    int result = bfs(a, b);
    cout << result << '\n';

    return 0;
}
