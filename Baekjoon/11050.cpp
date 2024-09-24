#include<bits/stdc++.h>
using namespace std;

int pick, cnt;
// 5, 2
void combi(int n, int k, int start)
{
    // n개 중에 k개 뽑기
    if(pick == k)
    {
        cnt++;
        return;
    }

    // 뽑기
    for(int i = start + 1; i < n; i++)
    {
        pick++;
        combi(n,k, i);
        pick--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    combi(n,k,-1);
    cout << cnt;

    return 0;
}