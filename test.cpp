#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int d[1000'000] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;

    d[1] = 0;
    for(int i = 2; i <= x; i ++)
    {
        // 최소값
        d[i] = d[i-1] + 1;
        if(i % 3 == 0)
        {
            d[i] = min(d[i],d[i/3] + 1);
        }
        if(i % 2 == 0)
        {
            d[i] = min(d[i],d[i/2] + 1);
        }
    }

    cout << d[x];
    return 0;
}