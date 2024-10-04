#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    int ret = 0;
    cin >> str;

    stack<char> stk;
    int crossStick = 0;
    int totalStick = 0;
    // 직전 입력이 (이면 true
    bool flag = false;

    for(char c : str)
    {
        // 레이저는 스택에서 막대기의 개수만큼 지나간다. 
        // 닫히지 않은 ( 개수 세기 
        if(c == '(')
        {
            flag = true;
            stk.push(c);
        }
        else if(c == ')')
        {
            // 얘는 확정
            stk.pop();   
            // 직전에 ( = 레이저
            if(flag)
            {
                // 쌓여있던 스택 크기 = 지금까지 막대기
                // = 겹친 막대기
                crossStick += stk.size();
                flag = false;
            }
            else
            {
                // ))
                // 직전에 )이면 
                // 지금 들어온 )는 막대기 끝 이라는 뜻 
                crossStick++;
                totalStick++;
            }
        }
    }
    // ret = crossStick + totalStick;
    cout << crossStick << " " << totalStick;
    return 0;
}