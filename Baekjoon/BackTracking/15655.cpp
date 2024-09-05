#include<bits/stdc++.h>
using namespace std;

const int MAX = 9;
int n, m;
int arr[MAX] = { 0, };
int combiArr[MAX] = { 0, };
int visited[MAX] = { 0, };
void print()
{
    for (int i = 0; i < m; i++)
    {
        cout << combiArr[i] << " ";
    }
    cout << '\n';
}

void dfs(int cnt, int idx)
{
    if (cnt == m)
    {
        print();
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            combiArr[cnt] = arr[i];
            // 다음 조합 인덱스
            // 시작점도 다음 걸로 갱신 -> 이걸로 순서 무시 효과(겹치지 않게)
            dfs(cnt + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    dfs(0, 0);

    return 0;
}