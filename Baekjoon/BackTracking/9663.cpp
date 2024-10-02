#include<bits/stdc++.h>
using namespace std;

// 미리 놓을 수 없는 지점 표시
bool isused1[40];       // 세로(왼쪽부터 위->아래)
bool isused2[40];       // 좌상단부터 우상향 대각선에 퀸이 있으면 T
bool isused3[40];       // 우상단부터 우하향 대각선에 퀸이 있으면 T

int cnt = 0;
int n;

void func(int cur)
{
    if(cur == n)
    {
        cnt++;
        return;
    }

    // 가로 = i
    for(int i = 0; i < n; i++)
    {
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) continue;
        // 표시
        isused1[i] = 1;
        isused2[i+cur] = 1;             // x+y가 같은 지점들 = 대각선
        isused3[cur - i + n - 1] = 1;   // x-y+n-1이 같은 지점들
        // 재귀
        func(cur + 1);
        // 복구
        isused1[i] = 0;
        isused2[i+cur] = 0;
        isused3[cur - i + n - 1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    // dfs를 써서 재귀, 백트래킹
    func(0);
    cout << cnt;


    return 0;
}