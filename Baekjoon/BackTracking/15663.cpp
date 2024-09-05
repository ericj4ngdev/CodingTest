#include<bits/stdc++.h>
using namespace std;

const int MAX = 9;
int n, m;
int arr[MAX] = { 0, };
int permuteArr[MAX] = { 0, };
int visited[MAX] = { 0, };
void print()
{
    for (int i = 0; i < m; i++)
    {
        cout << permuteArr[i] << " ";
    }
    cout << '\n';
}

void dfs(int cnt)
{
    if (cnt == m)
    {
        print();
        return;
    }
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        // 추가하려는 수가 직전에 추가한 순열 요소와 같다면 pass
        if (!visited[i] && temp != arr[i])
        {
            visited[i] = true;
            permuteArr[cnt] = arr[i];
            temp = permuteArr[cnt];

            dfs(cnt + 1);

            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    dfs(0);

    return 0;
}