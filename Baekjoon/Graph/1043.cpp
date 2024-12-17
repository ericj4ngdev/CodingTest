#include<bits/stdc++.h>
using namespace std;

int visited[51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int personCount, personNum = 0;
    vector<int> knowTruth;
    cin >> personCount;
    for (int i = 0; i < personCount; ++i)
    {
        cin >> personNum;
        knowTruth.push_back(personNum);
    }
    vector<vector<int>> party(m);
    vector<vector<int>> graph(n + 1);
    // 파티 개수만큼 입력
    for (int i = 0; i < m; ++i)
    {
        // 파티내 인원 입력
        int participants;
        cin >> participants;
        // 사람 번호 입력
        for (int j = 0; j < participants; ++j)
        {

            int num;
            cin >> num;
            party[i].push_back(num);                                                                    // j -> i
        }

        // 해당 파티에 참여한 사람끼리 그래프 잇기
        for (int j = 0; j < party[i].size() - 1; ++j)
        {
            graph[party[i][j]].push_back(party[i][j + 1]);
            graph[party[i][j + 1]].push_back(party[i][j]);
        }
    }


    // memset(visited, 0, sizeof(visited));                                                      // 괜히 함
    // 진실을 아는 사람을 시작으로 bfs돌리기
    for (int i = 0; i < knowTruth.size(); ++i)
    {
        queue<int> q;
        q.push(knowTruth[i]);
        visited[knowTruth[i]] = 1;
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            // 파티원 순회
            for (int j = 0; j < graph[cur].size(); ++j)                                         // i -> j
            {
                if (visited[graph[cur][j]] == 1)
                    continue;
                visited[graph[cur][j]] = 1;
                q.push(graph[cur][j]);
            }
        }
    }

    int count = 0;
    // 파티 내 진실아는 사람이 없으면 count++
    for (int i = 0; i < m; ++i)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); ++j)
        {
            // 한명이라도 진실을 알면 false하고 다음 파티
            if (visited[party[i][j]] == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }

    cout << count;

    return 0;
}
