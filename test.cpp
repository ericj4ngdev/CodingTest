#include<bits/stdc++.h>
using namespace std;

int d[101][100001];
int n, weight, value, k;
vector<pair<int, int>> item;

void dp()
{
    for(int limit = 1; limit <= k; limit++)
    {
        for(int row = 1; row <= n; row++)
        {
            if(item[row].first > limit)
                d[row][limit] = d[row-1][limit];
            else
                d[row][limit] = max(d[row-1][limit - item[row].first] + item[row].second, d[row-1][limit]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    item.push_back({0, 0}); // Dummy item
    for(int i = 0; i < n; ++i)
    {
        cin >> weight >> value;
        item.push_back({weight, value});
    }

    //초기화
    for(int r=0; r<=n; r++)
    {
        d[r][0] = 0;
    }
    for(int c = 0; c<=k; c++){
        d[0][c] = 0;
    }

    dp();

    cout << d[n][k];

    return 0;
}