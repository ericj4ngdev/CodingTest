#include <iostream>
#include <algorithm>
using namespace std;

// dp[i][j] = i번째 층까지 합들 중 j번째 수 
// dp[n][j]중 가장 큰 수가 답
int dp[504][504];
int tri[504][504];
int ret[504];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> tri[i][j]; 
        }
    }
    // 초기 조건
    dp[0][0] = tri[0][0];
    ret[0] = dp[0][0];
    // dp[1][0] = tri[0][0] + tri[1][0];
    // dp[1][1] = tri[0][0] + tri[1][1];
    // ret[1] = max(dp[1][0], dp[1][1]);

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + tri[i][j];
            }
            else if(j == i)
            {
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }
            else
            {
                dp[i][j] =  tri[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    ret[n-1] = *max_element(dp[n-1], dp[n-1] + n);  // 이 부분 수정


    cout << ret[n-1];

    return 0;
}