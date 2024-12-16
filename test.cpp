#include<bits/stdc++.h>
using namespace std;

#define SIZE 100
int visited[SIZE];

void bfs(vector<int>& connect, vector<vector<int>>& graph, int start)
{
    queue<int> q;
    q.push(start);

    while (q.size())
    {
        int cur = q.front();
        
        q.pop();
        for (int item : graph[cur])
        {
            if (visited[item]) continue;
            visited[item] = 1;
            // 연결성 표시
            connect[item] = 1;
            q.push(item);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            // graph[i][j] = temp;
            if (temp == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    cout << '\n';

    for (int i = 0; i < n; i++)
    {
        vector<int> answer(n, 0);
        memset(visited, 0, sizeof(visited));
        bfs(answer, graph, i);
        for (int item : answer)
        {
            cout << item << " ";
        }
        cout << '\n';
    }

    return 0;
}