#include<bits/stdc++.h>
using namespace std;

const int SIZE = 100001;
const int dx[] = {-1, 1, 2};
int ret, cnt;
int visited[SIZE];
int road[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int curpos, dest;
    cin >> curpos >> dest;
    
    // 목적지 표시
    road[dest] = 1;

    queue<int> q;
    visited[curpos] = 1;
    q.push(curpos);
    while(q.size())
    {
        int x = q.front();
        q.pop();
        // for(int it : {x-1, x+1, 2*x})
        for(int i = 0; i < 3; i++)
        {
            int nx = 0;
            // 순간이동은 방문 처리는 하되 횟수는 더하지 않는다.
            if(i == 2)
            {
                nx = x * dx[i];
                cnt++;
            }
            else
            {
                nx = x + dx[i];
            }
            if(nx < 0 || nx >= SIZE) continue;
            if(visited[nx]) continue;
            
            // 도착시 출력
            if(road[nx] == 1)
            {
                break;
            }

            // 지나온 횟수 더하기
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }

    cout << visited[dest] - cnt;


    return 0;
}