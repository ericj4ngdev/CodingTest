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
        // 세 가지 경우 중 최소값. 
        // 따라서 else if로 하면 안되고 다 해보면서 min을 체크한다. 
        // 최소값이란 조건때문에 DP뿐만이 아닌 min체크도 계속 했어야 한다. 

        // 최소값
        d[i] = d[i-1] + 1;
        if(i % 3 == 0)
        {
            d[i] = min(d[i],d[i/3] + 1);
        }
        // else if(i % 2 == 0)
        if(i % 2 == 0)
        {
            d[i] = min(d[i],d[i/2] + 1);
        }
    }

    cout << d[x];
    return 0;
}