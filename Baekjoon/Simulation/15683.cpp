#include<bits/stdc++.h>
using namespace std;

const int SIZE = 10;
int n, m, cnt;
int ret = 987654321;
int room[SIZE][SIZE];
vector<pair<int, int>> cctvs;

int dx[4] = { 1, 0, -1, 0 }; // 오른쪽, 위, 왼쪽, 아래
int dy[4] = { 0, -1, 0, 1 };

void mark(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || y < 0 || x >= m || y >= n || room[y][x] == 6) break;
        if (room[y][x] == 0) room[y][x] = 7; // 감시 영역 표시
    }
}

void simulate(int idx)
{
    // 개수가 되면 세기
    if (idx == cctvs.size())
    {
        int blindSpots = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (room[i][j] == 0) blindSpots++;
            }
        }
        ret = min(ret, blindSpots);
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int type = room[y][x];
    int backup[SIZE][SIZE];

    // 다음 cctv 방향 설정 dfs재귀
    for (int i = 0; i < 4; i++)
    {
        memcpy(backup, room, sizeof(room));

        if (type == 1) {
            mark(x, y, i);
        }
        else if (type == 2) {
            mark(x, y, i);
            mark(x, y, i + 2);
        }
        else if (type == 3) {
            mark(x, y, i);
            mark(x, y, i + 1);
        }
        else if (type == 4) {
            mark(x, y, i);
            mark(x, y, i + 1);
            mark(x, y, i + 2);
        }
        else if (type == 5) {
            mark(x, y, i);
            mark(x, y, i + 1);
            mark(x, y, i + 2);
            mark(x, y, i + 3);
        }

        simulate(idx + 1);
        memcpy(room, backup, sizeof(room));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
            if (room[i][j] > 0 && room[i][j] < 6)
            {
                cctvs.push_back({ j, i });
            }
        }
    }
    simulate(0);
    cout << ret << "\n";

    return 0;
}

