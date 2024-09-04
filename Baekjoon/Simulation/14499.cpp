#include<bits/stdc++.h>
using namespace std;

const int SIZE = 21;
int board[SIZE][SIZE];
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};
// x가 세로 좌표
int height, width, x, y, cmdcnt;
int cmd;
int dice[7];


void RollDice(int dir)
{
    int temp = dice[2];
    // 동쪽
    if(dir == 1)
    {        
        dice[2] = dice[6];
        dice[6] = dice[4];
        dice[4] = dice[5];
        dice[5] = temp;
    }
    else if(dir == 2)
    {
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[6];
        dice[6] = temp;
    }
    else if(dir == 3)
    {
        dice[2] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = temp;
    }
    else if(dir == 4)
    {
        dice[2] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[1];
        dice[1] = temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> height >> width >> x >> y >> cmdcnt;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            cin >> board[i][j];
        }
    }

    // 벡터 2개?
    for(int i = 0; i < cmdcnt; i++)
    {
        cin >> cmd;
        // 이동 후 칸 = 0  -> 바닥면 수 -> 칸에 복붙
        // 이동 후 칸 != 0 -> 칸 수 -> 바닥면 복붙, 칸 수 = 0
        int nx = x + dx[cmd - 1];
        int ny = y + dy[cmd - 1];
        // 오버 플로우
        if(nx >= height || ny >= width || nx < 0 || ny < 0) continue;
        // 이동
        x = nx;
        y = ny;
        // 이동 후 바닥면
        // 주사위 시스템 만들기
        RollDice(cmd);
        
        if(board[x][y] == 0)
        {
            // 바닥면 -> 칸에 복붙
            board[x][y] = dice[4];
        }
        else
        {
            // 칸 수 -> 바닥면 복붙, 칸 수 = 0
            dice[4] = board[x][y];
            board[x][y] = 0;
        }
        cout << dice[2] << '\n';        
    }

    return 0;
}