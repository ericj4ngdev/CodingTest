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
    // ��Ƽ ������ŭ �Է�
    for (int i = 0; i < m; ++i)
    {
        // ��Ƽ�� �ο� �Է�
        int participants;
        cin >> participants;
        // ��� ��ȣ �Է�
        for (int j = 0; j < participants; ++j)
        {

            int num;
            cin >> num;
            party[i].push_back(num);                                                                    // j -> i
        }

        // �ش� ��Ƽ�� ������ ������� �׷��� �ձ�
        for (int j = 0; j < party[i].size() - 1; ++j)
        {
            graph[party[i][j]].push_back(party[i][j + 1]);
            graph[party[i][j + 1]].push_back(party[i][j]);
        }
    }


    // memset(visited, 0, sizeof(visited));                                                      // ���� ��
    // ������ �ƴ� ����� �������� bfs������
    for (int i = 0; i < knowTruth.size(); ++i)
    {
        queue<int> q;
        q.push(knowTruth[i]);
        visited[knowTruth[i]] = 1;
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            // ��Ƽ�� ��ȸ
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
    // ��Ƽ �� ���Ǿƴ� ����� ������ count++
    for (int i = 0; i < m; ++i)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); ++j)
        {
            // �Ѹ��̶� ������ �˸� false�ϰ� ���� ��Ƽ
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
