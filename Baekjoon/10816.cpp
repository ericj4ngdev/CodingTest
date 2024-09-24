#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;

    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
        // 해당 수가 몇 개 있는지 
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp2;
        cin >> temp2;
        cout << mp[temp2] << " ";
        // cin >> b[i];
        // a에 있는 b[i]의 개수 
    }

    return 0;
}