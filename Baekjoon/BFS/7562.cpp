#include <bits/stdc++.h>
using namespace std;

const int SIZE = 301;
int boardSize;
int ret  = 987654321;
pair<int,int> cur;
pair<int,int> dest;
int visited[SIZE][SIZE];
const int dx[] = {2, 1, -1,-2, -1, -2, 1, 2};
const int dy[] = {1, 2, 2, 1, -2, -1, -2, -1};

void bfs()
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[cur.second][cur.first] = 1;
    q.push(cur);
    while(q.size())
    {
        int x, y = 0;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({nx,ny});
            if(nx == dest.first && ny == dest.second)
            {
                ret = min(ret,visited[ny][nx] - 1);
            }
        }
    }
}

int main()
{
    int testcase = 0;
    cin >> testcase;
    while(testcase--)
    {
        ret = 987654321;
        cin >> boardSize;
        cin >> cur.first >> cur.second;
        cin >> dest.first >> dest.second;
        // cout << "cur : " << cur.first << ", " << cur.second << '\n';
        // cout << "dest : " << dest.first << ", " << dest.second << '\n';
        if(cur == dest)
        {
            ret = 0;
        }
        else
        {
            bfs();
        }
        cout << ret << '\n';
    }
    return 0;
}