#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int d[1001] = {0,};
        
    d[1] = 1;
    d[2] = 3;
    
    for(int i = 3; i <= n; i++)
    {
        d[i] = (d[i-1] + d[i-2]*2) % 10007;
    }

    cout << d[n];

    return 0;
}