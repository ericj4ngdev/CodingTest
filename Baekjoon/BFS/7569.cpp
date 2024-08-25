#include<bits/stdc++.h>
using namespace std;

const int SIZE = 101;
int m, n, h, ret;
queue<tuple<int, int, int>> q;
int box[SIZE][SIZE][SIZE];
int dist[SIZE][SIZE][SIZE];
const int dx[] = {-1, 0, 1, 0, 0, 0};
const int dy[] = {0, 1, 0, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

void Input()
{
    cin >> m >> n >> h;   
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                     q.push({k, j, i});
                    dist[i][j][k] = 0;
                } 
                else 
                {   
                    // 토마토가 없거나 안익은 경우
                    dist[i][j][k] = -1;
                }
            }
        }
    }
}

void PrintBox()
{
    cout << '\n';
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cout << box[i][j][k] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

void bfs()
{
    while(q.size())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
            // 안익은 토마토 & 토마토가 없거나 안익은 경우 
            if (box[nz][ny][nx] == 0 && dist[nz][ny][nx] == -1) {
                dist[nz][ny][nx] = dist[z][y][x] + 1;
                q.push({nx, ny, nz});
            }
        }        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();

    bfs();

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if (box[i][j][k] == 0 && dist[i][j][k] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                ret = max(ret, dist[i][j][k]);
            }
        }
    }
    cout << ret;
    return 0;
}