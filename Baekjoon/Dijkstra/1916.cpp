#include<bits/stdc++.h>
using namespace std;

int n, m;
int start, dest;
const int CITY_COUNT = 1000;
const int BUS_SIZE = 100000;
// vector<vector<int>> graph;
int graph[CITY_COUNT][CITY_COUNT];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int to, from, cost;
    for(int i = 0; i < m; ++i)
    {
        cin >> to >> from >> cost;
        graph[to][from] = cost;
        // graph[from][to] = cost;
    }
    cin >> start >> dest;

    // start -> dest로 가는데 드는 최소 비용
    // 다익스(노드 비용도 제각각이고 단방향임)
    

    return 0;
}
