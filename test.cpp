#include<bits/stdc++.h>
using namespace std;

const int SIZE = 54;
int n, l, r, ret, sum;
int a[SIZE][SIZE];
int visited[SIZE][SIZE];
vector<pair<int, int>> v;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        // 연합국인가? 
        if(visited[ny][nx]) continue;
        int gap = abs(a[ny][nx] - a[y][x]);
        if(gap >= l && gap <= r)
        {
            visited[ny][nx] = 1;
            sum += a[ny][nx];
            v.push_back({ny,nx});
            dfs(ny,nx);
        }
    }
    return;
}

int main()
{
    cin >> n >> l >> r;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // 인구 수 차이

    // dfs로 연결 컴포 계산 = 연합국 여부
    // visited = 너 연합국

    while(true)
    {
        bool flag = 0;
        memset(visited,0,sizeof(visited));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // 연합국인 적이 없다면
                if(!visited[i][j])
                {
                    // 초기화
                    sum = 0;
                    v.clear();
                    dfs(i,j);
                    // 연합국이 없다면 패스
                    if(v.size() == 0) continue;
                    for(pair<int, int> pos : v)
                    {   
                        a[pos.first][pos.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }   
        }
        // 연합국 없음. 더이상 인구 이동 X
        if(!flag) break;
        ret++;
    }
    cout << ret;
    return 0;
}

