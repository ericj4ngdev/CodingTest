#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE = 9;
int h, w, ret;
int lab[MAXSIZE][MAXSIZE];
int backup[MAXSIZE][MAXSIZE];
// int visited[MAXSIZE][MAXSIZE];
int safeZone;
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;

void SetWall(int idx)
{
    backup[blank[idx].second][blank[idx].first] = 1;
}

void Spread(int x, int y)
{
    backup[y][x] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        // 비어있으면 확산
        if (backup[ny][nx] == 0)
        {
            Spread(nx,ny);
        }
    }
}

void CountSafe()
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (backup[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    ret = max(ret, cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 0)
            {
                blank.push_back({ j,i });
            }
            if (lab[i][j] == 2)
            {
                virus.push_back({ j,i });
            }
        }
    }

    // 3중 for문
    for (int i = 0; i < blank.size(); i++)
    {
        for (int j = i + 1; j < blank.size(); j++)
        {
            for (int k = j + 1; k < blank.size(); k++)
            {
                memcpy(backup, lab, sizeof(lab));
                // 벽 세우는 함수
                SetWall(i);
                SetWall(j);
                SetWall(k);

                // 확산 함수
                for(auto it : virus)
                {
                    Spread(it.first, it.second);
                }

                // 안전지대 크기 세는 함수
                CountSafe();
                memset(backup, 0, sizeof(backup));
            }
        }
    }

    cout << ret;
    return 0;
}