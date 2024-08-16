#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000001], ret[1000001];
stack<int> s;

int main()
{
    memset(ret,-1,sizeof(ret));

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        while(s.size() && a[s.top()] < a[i])
        {
            // 오큰수 결정
            ret[s.top()] = a[i];
            // 결정된 인덱스는 스택에서 제외
            s.pop();
        }
        // 스택에 인덱스 저장
        s.push(i);
    }

    for(int i = 0; i < n; i++) cout << ret[i] << " ";
    
    return 0;
}