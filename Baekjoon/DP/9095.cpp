#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;

    // 규칙
    // d[i] = i를 만드는 방법
    // d[1] = 1; = 1
    // d[2] = d[1] + 1; = 2
    // d[3] = d[2] + d[1] + 1; = 4
    // d[4] = d[3] + d[2] + d[1] = 7
    // d[5] = 
    // 3 = 2+1 = 1+2
    //   = 1+1+1
    //   = 3
    int d[11];
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    // 기저 
    for(int i = 4; i <= 10; i++)
    {        
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    while(testcase--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}