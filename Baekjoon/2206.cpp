#include<bits/stdc++.h>
using namespace std;

int n, m;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int maze[1001][1001];
int visited[1001][1001];

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 오버플로우
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            // 이미 방문
            if(visited[ny][nx] > 0) continue;
            // 길이면
            if(maze[ny][nx] == 1)
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
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            maze[i][j] = str[j] - '0';
        }
    }

    bfs();

    cout << visited[n-1][m-1];

    return 0;
}