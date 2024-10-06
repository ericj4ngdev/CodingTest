#include<bits/stdc++.h>
using namespace std;

int n;
char lc[30];
char rc[30];

void PreOrder(char cur)
{
    cout << cur;
    if(lc[cur - 'A'] != '.') PreOrder(lc[cur - 'A']);
    if(rc[cur - 'A'] != '.') PreOrder(rc[cur - 'A']);
}

void InOrder(char cur)
{
    if(lc[cur - 'A'] != '.') InOrder(lc[cur - 'A']);
    cout << cur;
    if(rc[cur - 'A'] != '.') InOrder(rc[cur - 'A']);
}

void PostOrder(char cur)
{
    if(lc[cur - 'A'] != '.') PostOrder(lc[cur - 'A']);
    if(rc[cur - 'A'] != '.') PostOrder(rc[cur - 'A']);
    cout << cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {        
        char c, l, r;
        cin >> c >> l >> r;
        // 알파벳 순으로 보정
        if(l != '.') lc[c - 'A'] = l;
        if(r != '.') rc[c - 'A'] = r;
        // cin >> root[i] >> lc[i] >> rc[i];        
    }
    PreOrder('A');
    cout << '\n';
    InOrder('A');
    cout << '\n';
    PostOrder('A');

    return 0;
}