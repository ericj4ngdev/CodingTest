#include<bits/stdc++.h>
using namespace std;

int test, m,n,k;
int x, y;
int a[54][54];
int visited[54][54];
const int dy[] = { -1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1};
int ret;

int main()
{
    // scanf("%d %d %d", &m, &n, &k);
    cin >> test;
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &x, &y);
        a[y][x] = 1;        
    }

    queue<pair<int, int>> q;
    q.push({0,0});

    while(test)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j]==0) continue;
                // 방문한 적 있으면 pass
                if(visited[i][j]) continue;
            
                // 뭉탱이 검사
                while(q.size())
                {
                    y = q.front().first;
                    x = q.front().second;
                    q.pop();

                    for(int l = 0; l < 4; l++)
                    {
                        int ny = y + dy[l];
                        int nx = x + dx[l];

                        if(nx < n || nx > 0 || ny < m || ny > 0 || a[ny][nx] == 0) continue;
                        if(visited[ny][nx]) continue;
                        visited[ny][nx] = 1;
                        q.push({ny, nx});           // 방문 표시
                    }
                }
                ret++;
            }
        }
        cout << ret << '\n';
        test--;
    }

    return 0;
}