#include<bits/stdc++.h>
using namespace std;

const int SIZE = 104;
int n, x, y, dir, gen, cnt;
int board[SIZE][SIZE];

void MakeCurve(int x, int y, int nx, int ny)
{
    // 끝점 기준

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        
        // 3 3 0 1
        // 4 2 1 3
        // 4 2 2 1
        cin >> x >> y >> dir >> gen;
        vector<int> dirInfo;
        dirInfo.push_back(dir%4);
        board[y][x] = 1;
        
                
        for(int j = 0; j < gen; j++)
        {
            // 방향 벡터의 개수 갱신
            int vSize = dirInfo.size();
            // 역순으로 뱡향 정보 갱신, 추가
            for(int k = vSize - 1; k >= 0; k--)
            {
                dirInfo.push_back((dirInfo[k] + 1) % 4);
            }
        }

        // 커브 그리기
        for(int j = 0; j < dirInfo.size(); j++)
        {
            // 0세대 드래곤 커브점
            if(dirInfo[j] == 0)
            {
                x++;            
            }
            else if(dirInfo[j] == 1)
            {
                y--;
            }
            else if(dirInfo[j] == 2)
            {
                x--;
            }
            else if(dirInfo[j] == 3)
            {
                y++;            
            }
            board[y][x] = 1;
        }
    }

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            // 커브 없으면 패스
            if(board[i][j] == 0) continue;
            // 오버플로우
            
            // 4개 꼭지점 확인
            if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}

