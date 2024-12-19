#include <bits/stdc++.h>
using namespace std;

int bfs(long a, long b) 
{
    queue<pair<long, int>> q; // {현재 값, 연산 횟수}
    q.push({a, 1}); // 시작 값과 초기 연산 횟수
    
    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        // 목표값에 도달한 경우
        if (cur == b) {
            return cnt;
        }

        // 가능한 다음 상태 탐색
        for (long nxt : {cur * 2, cur * 10 + 1}) 
        {
            // b를 초과하면 탐색 중단
            // 보통 여기때문에 q.size()가 0이 된다. 
            if (nxt > b) continue; 
            q.push({nxt, cnt + 1}); // 큐에 새로운 상태 추가
        }
    }

    return -1; // 목표값에 도달하지 못한 경우
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
