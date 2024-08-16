#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void check(string str)
{
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') cnt++;
        else if(str[i] == ')') cnt--;
        if(cnt < 0)
        { 
            cout << "NO" << '\n';
            return;
        }
    }

    if(cnt == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main()
{
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> str;
        check(str);
    }
    return 0;
}