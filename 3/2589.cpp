#include <bits/stdc++.h>
using namespace std;

char a[51][51];
int visited[51][51];
int n, m, ret;
vector<pair<int, int>> LandPos;

const int dx[4] = { -1, 0 , 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

void bfs(int y, int x)
{
    memset(visited, 0, sizeof(visited));        // 0으로 초기화
    // 최장거리 2개

    // ==================
    visited[y][x] = 1;
    // ==================
    queue<pair<int, int>> q;

    q.push({ y,x });      // 시작지점

    while (q.size())
    {
        // ==================
        // q에서 좌표 얻기
        y = q.front().first;
        x = q.front().second;
        q.pop();                    // 바로 없애기 
        // ==================

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 밖 or 바다
            if (nx >= m || nx < 0 || ny < 0 || ny >= n || a[ny][nx] == 'W') continue;
            // 방문한 적
            if (visited[ny][nx] > 0) continue;         // 여기가 오류

            // 방문 표시
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
            ret = max(ret, visited[ny][nx]);
        }
    }
    return;
}

// 육지 사이 거리중 가장 큰 값?
// bfs?
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            // scanf(" %c", &a[i][j]);
            if (a[i][j] == 'L')
            {
                LandPos.push_back({ i,j });
            }
        }
    }

    for (pair<int, int> pos : LandPos)
    {
        bfs(pos.first, pos.second);
    }

    cout << ret - 1;

    return 0;
}