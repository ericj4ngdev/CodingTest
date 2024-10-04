#include<bits/stdc++.h>
using namespace std;

int numComputers, numEdges;
// 감염된 컴퓨터 수 
int cnt;
vector<int> graph[101];
int virus[101];

void dfs(int start)
{
    virus[start] = 1;
    // 인접 노드 순회
    for(int com : graph[start])
    {
        // 이미 감염시 패스
        if(virus[com] > 0) continue;
        // 감염시키면서 cnt증가        
        cnt++;
        dfs(com);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> numComputers;
    cin >> numEdges;
    for(int i = 0; i < numEdges; i++)
    {
        int lCom, rCom;
        cin >> lCom >> rCom;
        // 간선 정보 입력
        graph[lCom].push_back(rCom);
        graph[rCom].push_back(lCom);
    }

    dfs(1);

    cout << cnt;

    return 0;
}