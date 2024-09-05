#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
int n, m;
int arr[MAX]={0,};

void dfs(int depth)
{
    // 다 뽑으면 출력
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;    
    }

    // 뽑자
    for(int i = 1; i <= n; i++)
    {
        arr[depth] = i;
        dfs(depth + 1);
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