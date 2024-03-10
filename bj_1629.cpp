#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b,c;

ll go(ll a, ll b)
{
    if(b == 1) return a%c;
    ll ret = go(a,b/2);                 // 이 값을 저장하는 것이 재귀의 핵심
    ret = (ret * ret) % c;
    // 홀수이면 한번 더
    if(b%2 == 1) { ret = (a * ret) % c; }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << go(a,b);

    return 0;
}