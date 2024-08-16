#include<bits/stdc++.h>
using namespace std;

int r, c;
char a[1001][1001];
int visited[1001][1001], fire[1001][1001];
// 불 시작지점 => 
vector<pair<int, int>> Exit;
pair<int, int> playerpos;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};


void SpreadFire(pair<int,int> pos)
{
    // 불 = visited = 갈 수 없는 곳
    // 4방향 불번짐
    for(int i = 0; i < 4; i++)
    {
        int nx = pos.second + dx[i];
        int ny = pos.first + dy[i];

        if(nx >= c || nx < 0 || ny >= r || ny < 0) continue;
        fire[ny][nx] = 1;
    }    
}

void bfs(pair<int,int> pos)
{
    memset(visited, 0, sizeof(visited));
    visited[pos.first][pos.second] = 1;
    queue<pair<int,int>> q;
    q.push({pos.first, pos.second});

    // bfs로 탈출 탐색
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= c || nx < 0 || ny >= r || ny < 0 || visited[ny][nx]) continue;
            if(a[ny][nx] == '#' || fire[ny][nx] == 1) continue;

            // 만약 탈출 경로이면 return?
            if(a[ny][nx] == '.' && (ny == 0 || ny == (r - 1) || nx == 0 || nx == (c - 1)))
            {
                return;
            }

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});            
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
   
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'J') 
            {
                visited[i][j] = 1;
                playerpos = {i,j};
            }
            if(a[i][j] == 'F') 
            {
                fire[i][j] = 1;
            }
            // 탈출구 저장
            if(a[i][j] == '.' && (i == 0 || i == (r - 1) || j == 0 || j == (c - 1)))
            {
                Exit.push_back({i,j});
            }
        }
    }

    // 이동하면 사람 위치 바뀜
    // 도달할 떄까지 시간 경과
    while(true)
    {
        bfs(playerpos);
        // 매번 플레이어 위치에서 bfs로 탈출 경로 탐색
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if(a[i][j] == 'F') 
                {
                    SpreadFire({i,j});
                }
            }
        }
        // 플레이어 이동시  cnt 증가
        // cnt++;
        
        // if(cnt == 0) cout << "IMPOSSIBLE";
        / else cout << cnt;
    }


    return 0;
}