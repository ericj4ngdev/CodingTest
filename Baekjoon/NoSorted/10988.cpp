#include <bits/stdc++.h>
using namespace std;

deque<string> dq;
string str;
vector<char> a;

bool go()
{
    for(int i = 0; i < str.size() / 2; i++ )
    {
        if(a[i] == a[str.size()-1-i]) continue;
        else return false;
    }
    return true;
}

int main()
{
    cin >> str;
    for(int i =0; i < str.size(); i++){
        a.push_back(str[i]);
    }
    if(go()) cout << 1;
    else cout << 0;
}