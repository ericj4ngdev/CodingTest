#include<bits/stdc++.h>
using namespace std;

const int SIZE = 50;
int row, col;
int cnt;
int ground[SIZE][SIZE];
int visited[SIZE][SIZE];

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void dfs(int x, int y)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
        if(visited[ny][nx]) continue;
        // 배추가 있는 곳이면 방문
        if(ground[ny][nx] == 1)
        {
            dfs(nx,ny);
        }        
    }    
}

void bfs(int xx, int yy)
{
    queue<pair<int,int>> q;
    q.push({xx,yy});
    visited[yy][xx] = 1;

    // 방문표시
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
            if(visited[ny][nx]) continue;
            // 배추가 있는 곳이면 방문
            if(ground[ny][nx] == 1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 연결 컴포넌트 개수
    int testcase = 0;
    cin >> testcase;
    while (testcase--)
    {
        // 초기화
        vector<pair<int,int>> vegitable;
        int ret = 0;
        vegitable.clear();
        memset(ground, 0, sizeof(ground));
        memset(visited, 0, sizeof(visited));
        cin >> row >> col >> cnt;
        for(int i = 0; i < cnt; i++)
        {
            int x, y;
            cin >> x >> y;
            vegitable.push_back({x,y});
            ground[y][x] = 1;
        }

        // 배추 위치 순회
        for(pair<int,int> it : vegitable)
        {
            // 방문 시 패스
            if(visited[it.second][it.first]) continue;
            dfs(it.first, it.second);
            // bfs(it.first, it.second);
            ret++;
        }
        cout << ret << '\n';
    }

    return 0;
}
