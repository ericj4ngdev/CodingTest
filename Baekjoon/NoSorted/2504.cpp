#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    stack<char> stc;
    cin >> str;
    int ret = 0;
    int temp = 1;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            temp *= 2;
            stc.push(str[i]);
        }
        else if(str[i] == '[')
        {
            temp *= 3;
            stc.push(str[i]);
            
        }
        else if(str[i] == ')')
        {
            if(stc.empty() || stc.top() != '(')
            {
                ret = 0;
                break;
            }
            if(str[i-1] == '(')
            {
                // 더하고 원복
                ret += temp;
                temp /= 2;
                stc.pop();
            }
            else
            {
                // ] ) 인 경우 
                temp /= 2;
                stc.pop();
            }            
        }
        else if(str[i] == ']')
        {
            if(stc.empty() || stc.top() != '[')
            {
                ret = 0;
                break;
            }
            if(str[i-1] == '[')
            {
                ret += temp;
                temp /= 3;
                stc.pop();
            }
            else
            {
                temp /= 3;
                stc.pop();
            } 
        }
    }

    if(!stc.empty()) ret = 0;

    cout << ret;

    return 0;
}