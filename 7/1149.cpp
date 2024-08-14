#include<bits/stdc++.h>
using namespace std;

int dp[1001][4];
int r[1005], g[1005], b[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // dp[i][j] : i번째 집을 j색으로 칠했을 때, i번째 집까지 색칠한 최소 비용
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i] >> g[i] >> b[i];        
    }
    dp[1][0] = r[1];
    dp[1][1] = g[1];
    dp[1][2] = b[1];

    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = r[i] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = g[i] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = b[i] + min(dp[i-1][0], dp[i-1][1]);
    }

    cout << *min_element(dp[n], dp[n]+3);

    return 0;
}