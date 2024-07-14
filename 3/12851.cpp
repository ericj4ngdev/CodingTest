#include<bits/stdc++.h>
using namespace std;

int n, k, cnt, ret;
// cnt = 최단시간
// ret = 방법 수 
int a[1000001];

int main()
{   
    cin >> n >> k;
    
    // 같은 경우
    if(n == k) 
    {
        cout << 0 << "\n" << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(n);
    a[n] = 1;

    while(q.size())
    {
        // front()가져오고 pop
        int x = q.front();
        q.pop();
        // 셋 중에 하나
        for(int nx : {x-1, x+1, x*2})
        {
            // 범위 밖
            if(nx < 0 || nx >= 100000) continue;            
            // 방문한 적 O
            if(a[nx]) continue;
            a[nx] = a[x] + 1;
            q.push(nx);

            if(nx == k) 
            {
                ret++;
                cnt = min(cnt, (int)q.size());
                continue;
            }
        }
        
    }

    cout << cnt << '\n' << ret;

    return 0;
}