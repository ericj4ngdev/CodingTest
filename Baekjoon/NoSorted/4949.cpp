#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    while(true)
    {
        stack<int> stk;
        string str;
        getline(cin, str);
        if(str[0] == '.') return 0;
        for(char ch : str)
        {
            if(ch == '[' || ch == '(')
            {
                stk.push(ch);
            }

            if(ch == ']')
            {
                if(stk.empty()) 
                {
                    cout << "no" << '\n';
                    break;
                }
                if(stk.top() == '[')
                {
                    stk.pop();
                    continue;
                }
                else
                {
                    cout << "no" << '\n';
                    break;
                }
            }


            if(ch == ')')
            {
                if(stk.empty()) 
                {
                    cout << "no" << '\n';
                    break;
                }
                if(stk.top() == '(')
                {
                    stk.pop();
                    continue;
                }
                else
                {
                    cout << "no" << '\n';
                    break;
                }
            }


            // 예외 처리 
            if(ch == '.')
            {
                // 짝이 안맞은 상태로 끝난 경우 체크
                if(stk.empty()) 
                {
                    cout << "yes" << '\n';
                }
                else
                {
                    cout << "no" << '\n';
                }
                break;
            }
        }
    }

    return 0;
}