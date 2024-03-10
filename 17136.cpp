// cpp_practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<bits/stdc++.h> 
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int INF = 987654321;
int a[11][11], ret = INF, n = 10;
map<int, int> mp;

// 색종이 배치 가능 여부
bool check(int y, int x, int size)
{
    // 색종이가 벗어났는가? 
    if(y + size > n || x + size > n) return false;
    // 색종이 안에 0이 하나라도 있는가? 
    for(int i = y; i < y + size; i++)
    {
        for(int j = x; j < x + size; j++)
        {
            if(a[i][j] == 0) return false;
        }
    }
    return true;
}

void draw(int y, int x, int size, int color)
{
    for(int i = y; i < y + size; i++)
    {
        for(int j = x; j < x + size; j++)
        {
            a[i][j] == color;
        }
    }
}

void dfs(int y, int x, int cnt)
{
    if(cnt >= ret) return;
    if(x == n) { dfs(y+1,0,cnt); return; }
    if(y == n) { ret = min(cnt, ret); return; }
    if(a[y][x] == 0) { dfs(y,x+1,cnt); return; }

    for(int size = 5; size >= 1; size--)
    {
        if(mp[size]==5) continue;
        if(check(y,x,size))
        {
            mp[size]++;
            draw(y,x,size,0);
            dfs(y,x+size,cnt+1);
            draw(y,x,size,1);
            mp[size]--;
        }
    }
    return;
}


int main()
{
    fast();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}