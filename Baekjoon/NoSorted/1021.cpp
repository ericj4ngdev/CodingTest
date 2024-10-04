// https://www.acmicpc.net/problem/1021
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;
    int n = 0;
    int m = 0;
    cin >> n >> m;  // m <= n
    for(int i = 1; i <= n; i++)
    {        
        cin >> i;
        dq.push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        // loc = 뽑아내려고 하는 수의 위치
        int loc = 0;
        cin >> loc;
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
        // 직접 빼는 게 아니고 거리 계산하기
        // 오른쪽으로부터 얼마나 떨어져 있는지?

        // 1 ~ 10
        // loc을 front로 두기까지 연산 최소값(두면 1번 연산으로 뽑는건 카운트 X)
        // 2 ~ 10 1         1
        // 3칸 (9는 오른쪽으로부터 3번째 칸에 있다.)
        // 3 ~ 10 1         1       // 뽑는 건 X
        // 1 3 ~ 10         2
        // 10 1 3 ~ 9       3
        // 9 1 3 ~ 8        4
        // 3칸 (9는 오른쪽으로부터 3번째 칸에 있다.)
        // 1 3 ~ 8(4 4)

        // 중간 기점으로 어디에 가까운가...
        

    }
    

    return 0;
}