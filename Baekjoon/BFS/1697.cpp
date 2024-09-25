#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int SIZE = 100'001;
int visited[SIZE];
int ret;

void bfs(int start, int end)
{
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        int nx[] = { x + 1, x - 1, 2 * x };
        for (int pos : nx)
        {
            // 밖으로 나감
            if (pos < 0 || pos > SIZE) continue;
            // 이미 방문한 적 있음
            if (visited[pos] > 0) continue;
            visited[pos] = visited[x] + 1;
            // 도착이면 저장
            if (pos == end)
            {
                ret = visited[pos] - 1;
                break;
            }
            q.push(pos);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (n != k)
    {
        bfs(n, k);
    }

    cout << ret;

    return 0;
}