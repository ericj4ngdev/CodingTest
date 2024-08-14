#include<bits/stdc++.h>
using namespace std;

const int SIZE = 104;
int wide, height, num, cnt;
vector<int> area;
int ground[SIZE][SIZE];
int visited[SIZE][SIZE];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void PaintSquare(int LDx, int LDy, int RTx, int RTy)
{
    for(int j = LDy; j < RTy; j++)
    {
        for(int k = LDx; k < RTx; k++)
        {
            ground[j][k] = 1;
        }
    }
}

int dfs(int y, int x, int size)
{
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= wide || ny < 0 || ny >= height) continue;
        if(visited[ny][nx]) continue;

        // 면적 계산하기
        if(ground[ny][nx] == 0)
        {
            size++; 
            dfs(ny,nx, size);
        }
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> wide >> height >> num;
    for(int i = 0; i < num; i++)
    {
        int LDx, LDy, RTx, RTy;
        cin >> LDx >> LDy >> RTx >> RTy;
        PaintSquare(LDx, LDy, RTx, RTy);
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < wide; j++)
        {
            if(ground[i][j] == 0)
            {
                // 방문한 적이 없을 경우에만 색칠. 면적 계산
                if(visited[i][j] == 0)
                {
                    cnt++;
                    int size = dfs(i, j, 1);                    
                    area.push_back(size);
                }
            }
        }
    }

    cout << cnt << '\n';
    for(int temp : area)
    {
        cout << temp << " ";
    }
    return 0;
}