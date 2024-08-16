#include<bits/stdc++.h>
using namespace std;

int n, k;
// ret = 방법 수 
int visited[1000001], cnt[1000001];

int main()
{   
    cin >> n >> k;
    
    // 같은 경우
    if(n == k) 
    {
        cout << 0 << "\n" << 1;
        return 0;
    }
    
    visited[n] = 1; 
    cnt[n] = 1;
    queue<int> q;
    q.push(n);

    while(q.size())
    {
        // front()가져오고 pop
        int x = q.front();
        q.pop();
        // 셋 중에 하나
        for(int nx : {x-1, x+1, x*2})
        {
            // 범위 밖
            if(nx < 0 || nx > 100000) continue;   
            // 방문한 적 X
            if(!visited[nx])
            {
                q.push(nx);
                visited[nx] = visited[x] + 1;
                cnt[nx] += cnt[x];
            }
            else if(visited[nx] == visited[x] + 1)
            {
                cnt[nx] += cnt[x];
            }
        }        
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k];

    return 0;
}