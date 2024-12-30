// https://www.acmicpc.net/problem/11054
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 커지다가 작아지고 다시 커지기 직전까지 길이
    int n;   cin >> n;
    vector<int> v;
    vector<int> inc(n, 0);
    vector<int> dec(n, 0);
    vector<int> dp(n, 0);

    for(int i = 0; i < n; ++i)
    {
        int temp;  cin >> temp;
        v.push_back(temp);
    }
    
    for(int i = 0; i < n; ++i)
    {
        inc[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            // 증가 추세
            if(v[i] > v[j])
            {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    for(int i = n - 1; i >= 0; --i)
    {
        dec[i] = 1;
        for(int j = n - 1; j >= i; --j)
        {
            // 감소 추세
            if(v[i] > v[j])
            {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {        
        dp[i] = max(dp[i], inc[i] + dec[i] - 1);
        // cout << inc[i] << " + " << dec[i] << " = " << dp[i] << endl;
    }

    cout << *max_element(dp.begin(),dp.end());

    return 0;
}