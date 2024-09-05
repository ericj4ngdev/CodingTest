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

void dfs(int depth)
{
    if(depth == m)
    {
        print();
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            permuteArr[depth] = arr[i];
            dfs(depth + 1);
            visited[i] = false;
        }
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