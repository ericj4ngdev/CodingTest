#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// ȸ���� <= 50
int num;
// �׷���
vector<int> friends[54];
vector<int> score(51);
int visited[54];        // -1�� �ʱ�ȭ

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (q.size())
    {
        int x = q.front();
        q.pop();
        // ģ�� Ž��
        for (int i = 0; i < friends[x].size(); i++)
        {
            if (visited[friends[x][i]] >= 0 && visited[friends[x][i]] <= visited[x] + 1)
                continue;

            visited[friends[x][i]] = visited[x] + 1;
            q.push(friends[x][i]);
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> num;
    while (true)
    {
        int l, r;
        cin >> l >> r;

        if (l == -1 && r == -1)
            break;

        friends[l].push_back(r);
        friends[r].push_back(l);
    }

    vector<int> presidents;
    int minScore = 987654321;
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        memset(visited, -1, sizeof(visited));
        visited[i] = 0;
        bfs(i);
        // visited���� ���� ���� ������ �� ģ�� score
        score[i] = *max_element(visited, visited + num + 1);
        // cout << i << " score : " << score[i] << '\n';

        if (score[i] == minScore)
        {
            // �ּ� ����
            ans++;
            presidents.push_back(i);
        }
        else if(score[i] < minScore)
        {
            minScore = score[i];
            ans = 1;
            presidents.clear();
            presidents.push_back(i);
        }
    }

    // �ĺ� ����, �ĺ� ��
    cout << minScore << " " << ans << '\n';
    // ����Ʈ
    for (int item : presidents)
        cout << item << " ";

    return 0;
}