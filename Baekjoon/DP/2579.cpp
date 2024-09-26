#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;

    int stair[301] = {0,};
    int d[301] = {0,};
    
    for(int i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }
    d[1] = stair[1];
    d[2] = max(stair[2], stair[2] + d[1]);
    for(int i = 3; i <= n; i++)
    {
        d[i] = max(stair[i] + d[i-2], stair[i] + stair[i-1] + d[i-3]);
    }
    cout << d[n];

    return 0;
}