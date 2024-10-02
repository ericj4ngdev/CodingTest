#include<bits/stdc++.h>
using namespace std;

int sticker[2][100'001];
int dp[2][100'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> sticker[i][j];
            }
        }

        // 풀이
        // dp[i][j] = st[i][j]스티커까지의 합 중 최대값 
        // st[i][j]가 마지막이면 직전 스티커는 대각선으로 2가지 경우가 있다.
        // 1. 직전 대각선
        // 2. 전전 대각선
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[0][1] + dp[1][0];
        dp[1][1] = sticker[1][1] + dp[0][0];

        for(int i = 2; i < n; i++)
        {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);                        
        }
        int ret = 0;
        ret = max(dp[0][n-1],dp[1][n-1]);
        cout << ret << '\n';
    }    

    return 0;
}

