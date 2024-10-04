#include<bits/stdc++.h>
using namespace std;

int n;
 
int t[20];      // 걸리는 기간
int p[20];      // 금액
int d[20];      // d[i] : i-1번째 날까지 상담한 후 벌 수 있는 최대 금액
                //      : i번째 날 갖고 있는 돈(아직 i번째 날 일 안함)

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
        // d[i] : i번째 날 갖고 있는 돈 갱신
        // i번째 날 갖고 있는 돈 vs i-1번째날 갖고 있는 돈
        // ex) 모든 상담 걸리는 시간이 1이면 max안에 d[i]는 항상 0일 거임 
        //     그리고 d[i-1]에 의해 갱신
        // ex) 상담 걸리는 시간이 2이상이면 max안에 d[i]가 d[i-1]보다 클 수 있음        
        d[i] = max(d[i], d[i-1]);
        // 밑에 로직에 의해 위 로직이 유의미해짐

        // ====== i번째 날 상담을 할 경우, 미래에 받을 돈 갱신 ======
        // i + t[i] - 1 : 상담이 종료되는 날(= 돈 받는 날)
        int end = i + t[i] - 1;
        // end > 퇴사날(n) => 무의미, 패스
        // 작거나 같으면 end인 날의 d[end + 1] 갱신(= end날 상담 후 번 돈)
        if(end <= n)
        {            
            // d[i] + p[i] : 아까 확정한 d[i]에 i날의 일당 더한 거
            // 즉, "i번째날 상담했을 때, (end + 1)날까지 번 돈"과 비교해서 d[end + 1]갱신            
            // ex) 첫날 1 10이라도 d[1] = 0이고 d[2] = 10이다.
            d[end + 1] = max(d[end + 1], d[i] + p[i]);
        }
    }
    
    // d[n+1] : n번째 날(마지막 날)까지 일하고 난 후 받은 돈
    // 마지막꺼까지 체크하기 위해 max 로직 존재
    // ex) 마지막 날 입력이 1 10 이면 d[n+1] = d[n] + 10이다.
    cout << max(d[n], d[n+1]);

    return 0;
}

