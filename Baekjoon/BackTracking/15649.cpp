#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
int n, m;
int arr[MAX]={0,};
bool visited[MAX]={0,};

void dfs(int depth)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        // 아직 안썼다면
        if(!visited[i])
        {
            // 표시
            visited[i] = true;
            // 순열 배열에 추가
            arr[depth] = i;
            // 다음 인덱스까지 
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    dfs(0);

    return 0;
}