#include<bits/stdc++.h>
using namespace std;
int a[10][10], visited[10][10], n, m, ret;
// 0 : 안전 영역
// 1 : 벽
// 2 : 바이러스
vector<pair<int, int>> virusList;       // 바이러스 좌표
vector<pair<int, int>> wallList;        // 벽 건축가능한 좌표(빈공간 좌표)

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}
int solve(){
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0); 
    for(pair<int, int> b : virusList)
    {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    } 

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 0 && !visited[i][j])cnt++;
        }
    } 
    return cnt;  
}
int main()
{
    // 입력
    cin >> n >> m;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j});
            if(a[i][j] == 0) wallList.push_back({i, j});
        }
    }

    // 벽 3개 세우기 (조합)
    for(int i = 0; i < wallList.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < j; k++)
            {
                // 벽 3개 세움
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;

                // 바이러스 확산 후 안전 영역 max값 체크
                ret = max(ret, solve());

                // 원상복구
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}