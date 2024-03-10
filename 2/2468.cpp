#include <bits/stdc++.h>
using namespace std;

int a[104][104];
bool visited[104][104];
int x, y, n, h, ret = 1, cnt, ny, nx;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= n || nx < 0) {continue;}
        if(a[ny][nx] > h && !visited[ny][nx]) {dfs(ny,nx);}
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
        for(int j = 0; j < n; j++)
        {   
            cin >> a[i][j];
            h = max(h,a[i][j]);
        }
    }

    while(--h)
    {
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
		            // 안전구역 && 미방문 => 덩어리 개수 늘리고 dfs(색칠)
                if(a[i][j] > h && !visited[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        fill(&visited[0][0],&visited[0][0] + 104 * 104, false);
        // cout << h << " " << cnt << '\n';
        ret = max(ret, cnt);        
    }
    cout << ret;
}