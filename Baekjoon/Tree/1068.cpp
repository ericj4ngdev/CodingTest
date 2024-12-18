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

    // 재귀로 부모 찾기
    return IsDisConnected(p[start]);
}

bool Leaf(int node)
{
    for (int i = 0; i < n; ++i)
    {
        // 부모 배열에 있다면 자식이 있다는 뜻
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
    // 리프 노드 개수(자식이 없는 말단 노드)

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int parent;    cin >> parent;
        p[i] = parent;
    }

    int erase; cin >> erase;
    p[erase] = -2;
    // 부모 배열 순회시 말단 노드 찾기 가능?
    // dfs로 서브 트리 크기는 구했었는데 
    // 리프 노드 특징
    // 자식이 없다 = 배열 p에 없다. 

    // 그 전에 자기 최종 부모가 -2이면 끊어진것임
    // p[3] = 1 -> p[1] = -2이면 끊어진 것

    int answer = 0;
    // 배열 p 순회
    for (int i = 0; i < n; ++i)
    {
        if (IsDisConnected(i)) continue;

        // 리프 노드인가?
        if (Leaf(i))
        {
            answer++;
        }
    }

    cout << answer;


    return 0;
}