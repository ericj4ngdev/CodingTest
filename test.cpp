#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, test, cnt, ret;
int a[101][101], visited[101][101];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 외부 = pass
        if((ny > n || nx > m || nx <= 0 || ny <= 0)) continue;
        // 이미 방문했으면 pass
        // if(visited[ny][nx])

        // 색칠 공간 && 미방문 -> 개수 체크 
        if(a[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(ny,nx);
            cnt++;
        }
    }
}

int main()
{
    scanf("%d", &test);
    scanf("%d %d %d", &n, &m, &cnt);
    
    while(test--)
    {
        fill(a, a + 50 * 50, 0);
        cnt = 0;
        for(int i = 0; i < cnt; i++)
        {
            cin >> x >> y;
            a[y][x] = 1;
        }

        dfs(0,0);
        cout << cnt << '\n';
    }
    
    return 0;
}