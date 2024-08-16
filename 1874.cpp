#include<bits/stdc++.h>
using namespace std;

int a[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    stack<int> stk;
    vector<char> ans;

    int current = 1;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        while(current <= n)      // 얘까지도 이해는 됨. 
        { 
            // n이 될 때까지 push
            stk.push(current);
            ans.push_back('+');
            current++;            
        }

        // top이 입력값과 같다면 pop
        if(stk.top() == input)      // 얘는 바로 이해
        {
            stk.pop();
            ans.push_back('-');
        }
        else                       // 얘는 음....
        {
            cout << "NO";
            return 0;
        }
    }
    return 0;
}