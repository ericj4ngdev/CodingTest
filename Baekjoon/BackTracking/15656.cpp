#include<bits/stdc++.h>
using namespace std;

const int MAX = 9;
int n, m;
int arr[MAX] = {0,};
int permuteArr[MAX] = {0,};
int visited[MAX] = {0,};
void print()
{
    for(int i = 0; i < m; i++)
    {
        cout << permuteArr[i] << " ";
    }
    cout << '\n';
}

void dfs(int cnt)
{
    if(cnt == m)
    {
        print();
        return;
    }

    for(int i = 0; i < n; i++)
    {
            permuteArr[cnt] = arr[i];
            dfs(cnt + 1);
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    dfs(0);

    return 0;
}