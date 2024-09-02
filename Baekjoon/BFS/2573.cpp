#include<bits/stdc++.h>
using namespace std;

const int SIZE = 304;
int n, m;
int ocean[SIZE][SIZE];
int meltCnt[SIZE][SIZE];
int visited[SIZE][SIZE];
int ret, iceCnt;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void PrintA()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {   
            cout << ocean[i][j] << " ";
        }
        cout << '\n';
    }    
}

void dfs(int x, int y)
{
    // 방문 초기화 잊지말기
    // 방문표시
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(ocean[ny][nx] > 0)
        {
            dfs(nx,ny);
        }
    }
}

void adj(int x, int y)
{
    int meltPoint = 0;
    for(int i = 0; i < 4; i++)
    {        
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
        
        // 바다이면
        if(ocean[ny][nx] == 0)
        {
            meltPoint++;
        }
    }
    meltCnt[y][x] = meltPoint;
    // return meltPoint;
}

bool IsSepreate()
{
    memset(visited, 0, sizeof(visited));
    int pieceCnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {   
            // 빙하 + 방문 X
            if(ocean[i][j] >= 1 && visited[i][j] == 0)
            {
                dfs(j,i);
                pieceCnt++;    
                if(pieceCnt > 1) return true;    
            }
        }
    }    
    return false;    
}

void Melt()
{
    // 한번에 녹이기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ocean[i][j] > 0)
            {
                ocean[i][j] = ocean[i][j] - meltCnt[i][j];
                if(ocean[i][j] < 0) ocean[i][j] = 0;
            }            
        }
    }
    memset(meltCnt, 0, sizeof(meltCnt));
}

void Simulate()
{
    // 인접한 면 개수 구하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ocean[i][j] > 0)
            {
                adj(j,i);
            }            
        }
    }

    // 녹이기
    Melt();

    // 남아있는 빙하 개수
    iceCnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ocean[i][j] > 0)
            {
                iceCnt++;
            }            
        }
    }
    ret++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ocean[i][j];
            if(ocean[i][j] > 0)
            {
                iceCnt++;
            }
        }
    }
    // 녹이기 = 인접한 개수 세기
    while (iceCnt > 0) {
        Simulate();
        if (IsSepreate()) {
            cout << ret << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    
    return 0;
}