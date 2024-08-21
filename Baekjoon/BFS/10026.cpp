// 적록색약
// https://www.acmicpc.net/problem/10026

#include<bits/stdc++.h>
using namespace std;

const int SIZE = 101;
char picture[SIZE][SIZE];
char Redpicture[SIZE][SIZE];
bool visited[SIZE][SIZE];
const int dx[] = {-1, 0 , 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, normalCnt, redGreenCnt;

void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> picture[i][j];
            if(picture[i][j] == 'G')
            {
                Redpicture[i][j] = 'R';
            }
            else
            {
                Redpicture[i][j] = picture[i][j];
            }
        }
    }
}

void dfs_normal(int y, int x, char c)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || ny < 0|| ny >= n|| nx >= n) continue;
        if(visited[ny][nx]) continue;

        if(picture[ny][nx] == c)
        {
            dfs_normal(ny,nx, c);
        }
    }
}

void dfs_redgreen(int y, int x, char c)
{
    
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || ny < 0|| ny >= n|| nx >= n) continue;
        if(visited[ny][nx]) continue;

        if(Redpicture[ny][nx] == c)
        {
            dfs_redgreen(ny,nx, c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Input();

    // 정상인 DFS
    // 이중 for문 돌면서 dfs
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 방문 X라면 DFS
            if(!visited[i][j])
            {
                // 현재 색상
                dfs_normal(i, j, picture[i][j]);
                normalCnt++;
            }
        }
    }

    cout << normalCnt << " ";
    // ====================================
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {            
            // 방문 X라면 DFS
            if(!visited[i][j])
            {
                // 현재 색상
                dfs_redgreen(i, j, Redpicture[i][j]);
                redGreenCnt++;
            }
        }
    }

    cout << redGreenCnt;


    return 0;
}