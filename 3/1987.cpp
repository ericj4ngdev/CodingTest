#include <bits/stdc++.h>
using namespace std;

const int SIZE = 24;
char board[SIZE][SIZE];
bool visitedAlphabet[26];
bool visited[SIZE][SIZE];
int row, col, ret;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void DFS(int y, int x, int cnt)
{
    ret = max(ret, cnt);
    visited[y][x] = true;
    visitedAlphabet[board[y][x] - 'A'] = true;

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 외부
        if(nx < 0 || ny < 0 || nx >= col || ny >= row) continue;
        
        // 지나온 길인가?
        if(visited[ny][nx]) continue;

        // 밟았던 알파벳인가?
        if(visitedAlphabet[board[ny][nx] - 'A']) continue;    
    
        DFS(ny, nx, cnt + 1);
    }
    // 새로운 알파벳이라면 방문 표시 갱신
    visited[y][x] = false;
    visitedAlphabet[board[y][x] - 'A'] = false;    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pair<int,int> pos;
    
    // 지나온 알파벳에 visited표시
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }    

    DFS(0,0,1);
    
    cout << ret;
}