#include<bits/stdc++.h>
using namespace std;

int n,l,r;
int a[51][51], visited[51][51];
int sum, cnt;
vector<pair<int, int>> unity;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// 인접국가와의 인구 차이 따지고 연합에 추가 dfs
void CheckUnity(int y, int x, vector<pair<int, int>>& v)
{    
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= n || nx >= n || nx < 0 || ny < 0) continue;
        
        if(visited[ny][nx]) continue;   // 추가

        int gap = abs(a[y][x] - a[ny][nx]);
        if(gap >= l && gap <= r)
        {  
            // 연합국 표시
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];           // 추가
            CheckUnity(ny, nx, v);
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(0);
    // cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 인구수 입력
            cin >> a[i][j];
        }
    }

    // 2 20 50
    // 30 100
    // 10 80

    while(true)
    {
        bool flag = 0;          // 인구 이동 여부 따지기 위한 변수
        // 테스트 케이스 초기화
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {                
                // 연합된 적이 없다면
                // 여기서 visited는 인구 차이 조건 충족으로 연합 여부를 의미
                if(!visited[i][j])
                {
                    // 기존 연합 리스트 초기화
                    unity.clear();
                    // 해당 좌표에서 다시 dfs돌리기
                    visited[i][j] = 1;
                    unity.push_back({i,j});
                    sum = a[i][j];        // 추가
                    CheckUnity(i,j,unity);
                    // 만약 dfs했는데 인접국가가 없다면 continue
                    if(unity.size() == 1) continue;
                    // 있다면 인구수 계산
                    for(pair<int,int> pos : unity)
                    {
                        // 연합국가 인구수 한번에 계산
                        a[pos.first][pos.second] = sum / unity.size();
                        flag = 1;       // 인구 이동 일어났으므로 표시
                    }
                }
            }
        }
        if(!flag) break;        // 더이상 인구 이동이 불가한 경우 탈출
        cnt++;
    }
    
    cout << cnt;
    return 0;
}
