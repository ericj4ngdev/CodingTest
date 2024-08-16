#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string board, ret;
    cin >> board;
    board += ' ';

    // X개수
    int cnt = 0;
    for(int i = 0; i < board.size() - 1; i++)
    {

        if(board[i] == 'X') cnt++;
        if(board[i] == '.')
        {
            ret += '.';
            if(cnt % 2 == 1) break;
            else cnt = 0;       // 초기화
        }
        
        // 2이고 다음 칸이 X가 아닌 경우에만 BB 추가
        if(cnt == 2 && board[i+1] != 'X')
        {
            ret += "BB";
            cnt = 0;       // 초기화
        }
        else if(cnt == 4)
        {
            ret += "AAAA";
            cnt = 0;       // 초기화
        }
    }

    if(cnt % 2 == 1) cout << -1;
    else cout << ret;

    return 0;
}