#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<int> qu;
    
    // 제일 위 카드 버리기 = pop
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        qu.push(i);
    }

    // 위 pop              아래
    // (front)1 2 3 4 5 6 (back)
    // while 조건만으로는 해결하기 어려움
    while(true)
    {
        if(qu.size() == 1) break;
        // 버리기
        qu.pop();
        // 또 버리기 전에 체크
        int temp = qu.front();
        qu.pop();
        qu.push(temp);
    }

    cout<< qu.front();

    return 0;
}