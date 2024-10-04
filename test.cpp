#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int a[2][100'001] = {0,};
int dp[2][100'001] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // dp[i][j] = a[i][j]를 끝으로 하는 최대 점수
    // dp[0][j]와 dp[1][j] 중 최대값
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
                cin >> a[i][j];
            }
        }

        // 기저 사례
        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        dp[0][1] = a[0][1] + dp[1][0];
        dp[1][1] = a[1][1] + dp[0][0];
        // 메모
        for(int i = 2; i < n; i++)
        {
            dp[0][i] = a[0][i] + max(dp[1][i-2], dp[1][i-1]);
            dp[1][i] = a[1][i] + max(dp[0][i-2], dp[0][i-1]);
        }
        int ret = max(dp[0][n-1], dp[1][n-1]);
        cout << ret << '\n';
    }

    return 0;
}