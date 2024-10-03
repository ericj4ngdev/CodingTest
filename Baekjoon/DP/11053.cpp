#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[1001] = {0,};
    vector<int> dp(n,1);
    // dp[i] = a[i]를 끝으로 하는 가장 긴 증가하는 부분 수열의 길이
    
    // 수열 입력 받기
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++) 
        {
            // i = 1
            // a[1](20) > a[0] o
            // dp[1] = 2

            // i = 2
            // a[2](10) > a[0] x
            // a[2] > a[1] x
            // dp[2] = 1

            // i = 3
            // a[3] > a[0] o => dp[3] = max(dp[3], dp[0] + 1) = 2
            // a[3] > a[1] o => dp[3] = max(dp[3], dp[1] + 1) = dp[1] + 1 = 3
            // a[3] > a[2] o => dp[3] = max(dp[3], dp[2] + 1) = 3
            
            if (a[i] > a[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }    
    }
    
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}