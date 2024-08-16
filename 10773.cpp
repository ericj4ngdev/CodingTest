#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num = 0;
    int k = 0;
    cin >> k;
    stack<int> st;
    for(int i = 0; i < k; i++)
    {
        cin >> num;
        if(num == 0)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }
    int ret = 0;
    // 스택에 남아있는 수의 합
    while(st.size())
    {
        ret += st.top();
        st.pop();
    }

    cout << ret;

    return 0;
}