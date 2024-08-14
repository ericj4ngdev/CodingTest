#include<bits/stdc++.h>
using namespace std;

int d[11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase = 0;
    int n = 0;
    cin >> testcase;

    // 방법 구하기
    // 초기 조건 1,2,3
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i < 11; i++)
    {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    while(testcase--)
    {
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}