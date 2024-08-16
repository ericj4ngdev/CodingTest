#include <bits/stdc++.h>
using namespace std;

int n, ret, h, a[104][104], visited[104][104];
const int dx[]= {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        
        // 특정 높이
        if(!visited[ny][nx] && a[ny][nx] > h)
        {            
            dfs(ny, nx);
        }
    }
    return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    
    // 모든 높이에 대해 검사
    while(h < 100)
    {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // 안전 영역
                if(!visited[i][j] && a[i][j] > h)
                {
                    dfs(i, j);      // 이미 색칠 공부가 이루어짐
                    cnt++;
                }
            }
        }
        h++;
        ret = max(ret, cnt);
    }
    cout << ret << '\n';
    return 0;
}