// 24.1.13
#include <bits/stdc++.h>
using namespace std;
string s, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ') 
        {
            ret += ' ';
        }
        else if((int)s[i] >= 'a' && (int)s[i] <= 'z')
        {
            if((int)s[i] + 13 > 'z') ret += (int)s[i] - 13;
            else ret += (int)s[i] + 13;            
        }
        else if((int)s[i] >= 'A' && (int)s[i] <= 'Z')
        {
            if((int)s[i] + 13 > 'Z') ret += (int)s[i] - 13;
            else ret += (int)s[i] + 13;
        }
        else ret += s[i];
    }
    
    cout << ret << '\n';
    return 0;
}