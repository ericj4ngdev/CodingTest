#include<bits/stdc++.h>
using namespace std;

const int SIZE = 21;
int mp[SIZE][SIZE];
int dis[SIZE][SIZE];
int sharkSize = 2;
int n;
pair<int, int> sharkPos;
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

struct Fish
{
    // i, j
    pair<int, int> pos{ 21,21 };
    int dist = 9999;
};


// 가장 가까운 물고기 찾기
Fish bfs()
{
    memset(dis, 0, sizeof(dis));
    Fish neareastFish;
    // i, j = y, x
    queue<pair<int, int>> q;
    q.push(sharkPos);
    
    // 거리
    dis[sharkPos.first][sharkPos.second] = 1;
    while (q.size())
    {
        auto [y, x] = q.front();
        q.pop();

        // dis 갱신하고서 가장 가까운 먹을 수 있는 물고기를 반환.
        // 먹을 수 있는가?
        if (mp[y][x] > 0 && mp[y][x] < sharkSize)
        {
            // 가까운가??
            if (neareastFish.dist > dis[y][x])
            {
                neareastFish.dist = dis[y][x];
                neareastFish.pos = { y,x };
            }
            else if (neareastFish.dist == dis[y][x])
            {
                // 같으면 좌상단 검사
                // 가장 위쪽인가?
                if (neareastFish.pos.first > y)
                {
                    neareastFish.pos = { y,x };
                }
                else if (neareastFish.pos.first == y)
                {
                    // 가장 왼쪽
                    if (neareastFish.pos.second > x)
                    {
                        neareastFish.pos = { y,x };
                    }
                }
            }
        }

        // 인접 상하좌우 이동
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 오버플로우
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            // 갔던 길 못감
            if (dis[ny][nx] > 0) continue;
            // 크기가 sharkSize보다 크면 못지나감
            if (mp[ny][nx] > sharkSize) continue;
            // 같은 크기여도 먹을 수는 없다. 지나갈 순 있다.            
            dis[ny][nx] = dis[y][x] + 1;
            q.push({ ny,nx });
        }
        // if (neareastFish.pos.first != 21) break; // 가장 가까운 물고기 찾음
    }
    // 반환할 값
    // 물고기 위치
    // 물고기 거리
    // 시작할 때 1로 시작해서 복구
    neareastFish.dist -= 1;
    return neareastFish;
}


int solve()
{
    // fish중에서 가장 가까운 물고기 찾기
    // 가까운게 여러 개이면 위치상 i, j가 작은거
    pair<int, int> neareastFishPos = { 0,0 };
    int dist = INT_MAX;
    int moveCount = 0;
    int eatCount = 0;

    // fishPos가 0일때 까지
    // 먹을 수 있는 물고기가 없을 때까지
    while (true)
    {
        // 먹을 수 있는 것 중 가장 가까운 물고기까지 거리 계산
        Fish neareastFish = bfs();
        // 먹을 물고기 없음
        if (neareastFish.pos.first == 21) break;
        dist = neareastFish.dist;
        neareastFishPos = neareastFish.pos;

        // 이동
        moveCount += dist;
        mp[sharkPos.first][sharkPos.second] = 0;
        sharkPos = neareastFishPos;
        mp[sharkPos.first][sharkPos.second] = 0;

        // 사이즈 검사(사이즈만큼 먹었는지 확인 후 증가)
        eatCount++;
        
        if (eatCount == sharkSize)
        {
            sharkSize++;
            eatCount = 0;
        }
    }
    return moveCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 좌상단 우선
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mp[i][j];
            // 상어 위치 저장
            if (mp[i][j] == 9)
            {
                sharkPos = { i,j };
                mp[i][j] = 0;
            }
        }
    }
    // 먹을 수 있는 물고기와의 거리 계산
    // 가장 가까운 물고기

    cout << solve();

    return 0;
}