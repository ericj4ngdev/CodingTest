#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    int cnt = 0;
    for(int i = 0; i < num; i++)
    {
        string str;
        cin >> str;        

        stack<char> stk;
        for(char c : str)
        {
            // 비어 있는지 확인
            if(stk.empty())
            {
                stk.push(c);
            }
            else
            {
                if(stk.top() == c)
                {
                    stk.pop();
                }
                else
                {
                    stk.push(c);
                }
            }
        }

        if(stk.empty()) 
        {
            cnt++;            
        }
    }
    cout << cnt;

    return 0;
}