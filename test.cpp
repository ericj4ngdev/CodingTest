#include<bits/stdc++.h>
using namespace std;
int a[1000];
// dp[i] = a[i]를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    
    vector<int> dp(n,1);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            // a[i]가 마지막이면 직전 값보단 커야 갱신할 필요가 있다.
            // a[i]와 a[0~ i-1] 을 비교하고 dp[i]결정
            if(a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}