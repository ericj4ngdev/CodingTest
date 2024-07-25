#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int RopeNum = 0;
    int ret = 0;
    cin >> RopeNum;
    vector<int> capacity(0);

    for(int i = 0; i < RopeNum; i++)
    {
        int temp = 0;
        cin >> temp;
        capacity.push_back(temp);
    }

    // 우선순위 큐로 중량 큰거부터
    // 25/2 = 12.5인데 10이 최대이므로 20
    // min(로프 중량들) * 로프 개수
    sort(capacity.begin(), capacity.end(), cmp);

    for(int i = 0; i < RopeNum; i++)
    {
        ret = max(ret,capacity[i] * (i+1));
    }

    cout << ret;
    return 0;
}