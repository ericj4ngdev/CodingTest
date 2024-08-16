#include<bits/stdc++.h>
using namespace std;

const int damage[6][3] = 
{
    {9,3,1},
    {9,1,3},
    {3,1,9},
    {3,9,1},
    {1,9,3},
    {1,3,9}
};
int visited[64][64][64];
int n;
int scv[3];

struct A{
    int a, b, c;
};

queue<A> q;
string str;
vector<int> v;
map<int, int> mp;

int solve(int a, int b, int c)
{    
    visited[a][b][c] = 1;
    q.push({a,b,c});
    while(q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        // 모두 체력 없는 노드에 도달했다면 끝
        if(visited[0][0][0]) break;
        // 방문 
        for(int i = 0; i < 6; i++)
        {            
            // 데미지 주기
            int na = max(0, a - damage[i][0]);
            int nb = max(0, b - damage[i][1]);
            int nc = max(0, c - damage[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    // 0, 0, 0인 지점에 도달하기까지 최소값
    for(int i = 0; i < n; i++) cin >> scv[i];

    cout << solve(scv[0],scv[1],scv[2]);

    return 0;
}
