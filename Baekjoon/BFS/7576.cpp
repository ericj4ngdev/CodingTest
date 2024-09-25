#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1001;
int width, height, cnt, ret;
int box[SIZE][SIZE];
int visited[SIZE][SIZE];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
queue<pair<int,int>> q;

void bfs()
{
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            // 거리 >= 0 = '일수'가 계산된 토마토
            if(visited[ny][nx] >= 0) continue;
            // 일수가 아직 계산 안된 토마토
            visited[ny][nx] = visited[y][x] + 1;
            q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> width >> height;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            cin >> box[i][j];
            // 익은 거면 큐에 추가            
            if(box[i][j] == 1)
            {
                q.push({j,i});
                // 초기 visited[i][j]은 0
            }
            else if(box[i][j] == 0)
            {
                // 안 익은거면 -1
                visited[i][j] = -1;
            }
        }
    }

    // 확산
    bfs();

    
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 모두 익지 못한 상황
            if (visited[i][j] == -1)
            {
                // 적어도 하나가 못 익은 상태
                cout << -1;
                return 0;
            }
            ret = max(ret, visited[i][j]);
        }
    }

    cout << ret;


    return 0;
}