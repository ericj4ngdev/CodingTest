#include<bits/stdc++.h>
using namespace std;

const int SIZE = 104;
int m, n, k, space;
int a[SIZE][SIZE];
int visited[SIZE][SIZE];

struct Rect
{
public:
    pair<int, int> LeftDown;
    pair<int, int> RightTop;    
};
vector<int> rects;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        // 사각형 없는 곳이라면
        if(!visited[ny][nx] && a[ny][nx] != 1)
        {
            space++;        // 면적 증가
            dfs(ny, nx);
        }
    }
    return;
}

// 들어온 좌표로 배열 a에 표시.
void Draw(pair<int, int> LD, pair<int, int> RT)
{
    for(int i = m - RT.second; i <= m - 1 - LD.second; i++)
    {
        for(int j = LD.first; j <= RT.first - 1; j++)
        {
            a[i][j] = 1;
        }
    }
}

int main()
{
    cin >> m >> n >> k;
    Rect rect;
    for(int i = 0; i < k; i++)
    {
        cin >> rect.LeftDown.first >> rect.LeftDown.second >> rect.RightTop.first >> rect.RightTop.second;
        Draw({rect.LeftDown.first, rect.LeftDown.second}, {rect.RightTop.first, rect.RightTop.second});
    }

    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 덩어리 개수
            if(!visited[i][j] && a[i][j] == 0)
            {
                space = 1;      // 방문할 거리가 생겼으니 1로 초기화
                dfs(i,j);
                rects.push_back(space);
                cnt++;
            }            
        }
    }
    cout << cnt << '\n';
    sort(rects.begin(), rects.end());
    for(int i = 0; i < cnt; i++)
    {
        cout << rects[i] << " ";
    }    
    return 0;
}