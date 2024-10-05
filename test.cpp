#include<bits/stdc++.h>
using namespace std;

// dp[i] : 2*i번째 타일까지 채우는 경우의 수
int dp[1001];
int n;
// maze[][][0] 벽을 부수기 전 최단 거리
int BFS(int N, int M)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { 0, 0 } });
    while (!q.empty())
    {
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1)
            return maze[N - 1][M - 1][broken] + 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 벽 안 부순 경로에서 벽만남
            if (maze[nx][ny][0] == 1)
            {
                // 벽 안부숨
                if(broken == 0)
                {
                    // 부순 미로 갱신..?
                    maze[nx][ny][broken + 1] = maze[x][y][broken] + 1;
                    q.push({ 1, { nx, ny } });
                }
            }
            // 벽 안 부순 경로에서 길 => 통과 가능
            else if (maze[nx][ny][0] == 0) 
            {
                
                // broken 부쉈는가??
                if (broken == 1 && maze[nx][ny][broken])
                {
                    // 이미 탐색한 경우
                    continue;
                }
                // 안부순 미로 갱신
                maze[nx][ny][broken] = maze[x][y][broken] + 1;
                q.push({ broken, { nx, ny } });
            } 
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++)
    {
        // 2칸 비었을 때, 채울 수 있는 경우는 3가지이지만
        // 세로로 넣는 건 dp[i-1]에 포함되므로
        // dp[i-2]에 2가지 경우를 곱해야 한다. 
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }
    cout << dp[n];

    return 0;
}