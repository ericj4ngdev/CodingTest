#include<bits/stdc++.h>
using namespace std;

int n;
 
int t[20];      // 걸리는 기간
int p[20];      // 금액
int d[20];      // d[i] : i-1번째 날까지 상담한 후 벌 수 있는 최대 금액
                // 아직 i번째 날 일 안함

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    // d[1] = 0 : 첫날엔 0원

    for(int i = 1; i <= n; i++)
    {
        // d[i] : i-1번째까지 번 돈 갱신(아직 i번째날 일 안함)
        // 전날까지 일한 후 가진 돈이 곧 d[i]이기 때문
        d[i] = max(d[i], d[i-1]);

        // i번째 날 상담을 할 경우, 미래에 받을 돈 갱신
        // i + t[i] - 1 : 상담이 종료되는 날(= 돈 받는 날)
        int end = i + t[i] - 1;//1
        // end > 퇴사날(n) => continue
        // 작거나 같으면 end인 날의 d 갱신(= end날에 받을 돈 결정)
        if(end <= n)
        {            
            // d[i] + p[i] : 아까 확정한 d[i]에 i날의 상담 페이 더한 거
            // 즉, "i번째 날 상담했을 때, (end + 1)날까지 번 돈"과 비교해서 d[end + 1]갱신
            // + 1을 하는 이유는 돈은 다음날 받는다 생각해서 그러함 
            // 예를 들어 첫날 1 10이라도 d[1] = 0이고 d[2] = 10이다.
            d[end + 1] = max(d[end + 1], d[i] + p[i]);
        }
    }    
    
    // d[n+1] : n번째 날(마지막 날)까지 일하고 난 후 받은 돈
    // 마지막꺼까지 체크하기 위해 max 로직 존재
    // ex ) 마지막 날 입력이 1 10 이면 d[n+1] = d[n] + 10이다.
    cout << max(d[n], d[n+1]);

    return 0;
}

