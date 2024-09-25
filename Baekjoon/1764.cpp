#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    map<string, int> mp;
    vector<string> v;
    for(int i = 0; i < (n + m); i++)
    {
        string str;
        cin >> str;
        mp[str]++;
        if(mp[str] == 2)
        {
            v.push_back(str);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(auto item : v)
    {
        cout << item << '\n';
    }

    


    return 0;
}