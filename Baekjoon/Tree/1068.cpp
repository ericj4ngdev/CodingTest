#include<bits/stdc++.h>
using namespace std;

int p[51];
int n;

bool IsDisConnected(int start)
{
    if (p[start] == -2)
        return true;

    if (p[start] == -1)
        return false;

    // ��ͷ� �θ� ã��
    return IsDisConnected(p[start]);
}

bool Leaf(int node)
{
    for (int i = 0; i < n; ++i)
    {
        // �θ� �迭�� �ִٸ� �ڽ��� �ִٴ� ��
        if (node == p[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ���� ��� ����(�ڽ��� ���� ���� ���)

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int parent;    cin >> parent;
        p[i] = parent;
    }

    int erase; cin >> erase;
    p[erase] = -2;
    // �θ� �迭 ��ȸ�� ���� ��� ã�� ����?
    // dfs�� ���� Ʈ�� ũ��� ���߾��µ� 
    // ���� ��� Ư¡
    // �ڽ��� ���� = �迭 p�� ����. 

    // �� ���� �ڱ� ���� �θ� -2�̸� ����������
    // p[3] = 1 -> p[1] = -2�̸� ������ ��

    int answer = 0;
    // �迭 p ��ȸ
    for (int i = 0; i < n; ++i)
    {
        if (IsDisConnected(i)) continue;

        // ���� ����ΰ�?
        if (Leaf(i))
        {
            answer++;
        }
    }

    cout << answer;


    return 0;
}