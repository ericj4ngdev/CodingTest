#include<bits/stdc++.h>
using namespace std;

string s, a[100004];
map<string, int> mp;
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s] = i + 1;
        a[i+1] = s;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> s;
        if(atoi(s.c_str()) == 0)
        {
            cout << mp[s] << '\n';
        }
        else
        {
            cout << a[atoi(s.c_str())] << '\n';
        }
    }

    return 0;
}