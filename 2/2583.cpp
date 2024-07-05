#include <bits/stdc++.h>
using namespace std;

#define y1 aaaa 

int n, m, k, ret;
int x, y, nx, ny, x1, y1, x2, y2;
int dy[4] = { -1, 0 , 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int a[104][104], visited[101][101];
vector<int> v;
int wide;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    wide++;     // 넓이
    for (int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        // 도달 가능 && 미방문
        if (!visited[ny][nx] && a[ny][nx] == 2)
        {
            dfs(ny, nx);
        }
    }
}

// 1 : 사각형
// 2 : 빈 공간

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    fill(&a, &a + n * m, 2);

    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // 사각형 색칠
        for (int i = n - y2; i <= n - y1; i++)
        {
            for (int j = x1; j <= x2 - 1; j++)
            {
                if (a[i][j] == 1) continue;
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == 2)
            {
                ret++;
                dfs(i, j);
                v.push_back(wide);
                wide = 0;
            }
        }
    }
    cout << ret;
    cout << '\n';
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}