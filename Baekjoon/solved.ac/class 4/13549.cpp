#include<bits/stdc++.h>
using namespace std;

const int SIZE = 100'001;
vector<int> dist(SIZE, INT_MAX);

int dijk(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ dist[start], start });

    while (pq.size())
    {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur == end) return curCost;
        

        // 현재 비용이 더 크면 패스
        // if (curCost > dist[cur]) continue;

        vector<pair<int, int>> v = { {1, cur + 1}, {1, cur - 1}, {0, cur * 2} };
        // 경우의 수 순회
        for (const auto& [nxtCost, nxt] : v)
        {
            if (nxt >= SIZE || nxt < 0) continue;
            if (dist[nxt] > curCost + nxtCost)
            {
                dist[nxt] = curCost + nxtCost;
                pq.push({ dist[nxt], nxt});
            }            
        }
    }
    return dist[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    cout << dijk(n, k);
    return 0;
}